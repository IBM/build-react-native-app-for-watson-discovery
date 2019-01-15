import React from 'react';
import { View, Text, TouchableHighlight } from 'react-native';
import { Actions } from 'react-native-router-flux';

export default class Insights extends React.Component {
  constructor(props) {
    super(props);
  }

  handleRefresh() {
    this.setState({refreshing: true}, () => this.fetchKeywords());
  }

  render() {
    const { subTitleStyle, contentStyle, linkStyle } = styles;

    return (
      <View>
        <Text style={subTitleStyle}>Sentiment</Text>
        <Text style={contentStyle}>
          {this.props.enriched_text.sentiment && this.props.enriched_text.sentiment.document.label} ({this.props.enriched_text.sentiment && this.props.enriched_text.sentiment.document.score})
        </Text>

        <Text></Text>

        <Text style={subTitleStyle}>Keywords</Text>
        {this.props.enriched_text.keywords && this.props.enriched_text.keywords.slice(0,5).map((r, i) => (
          <TouchableHighlight key={i} onPress={() => Actions.list({keyword: r.text})} >
            <Text key={i} style={linkStyle}>
              {r.text} ({r.relevance})
            </Text>
          </TouchableHighlight>
        ))}

        <Text></Text>

        <Text style={subTitleStyle}>Concepts</Text>
        {this.props.enriched_text.concepts && this.props.enriched_text.concepts.slice(0,5).map((r, i) => (
          <TouchableHighlight key={i} onPress={() => Actions.list({keyword: r.text})} >
            <Text key={i} style={linkStyle}>
              {r.text} ({r.relevance})
            </Text>
          </TouchableHighlight>
        ))}

      </View>
    );
  }
}

const styles = {
  subTitleStyle: {
    fontWeight: 'bold',
    fontSize: 14,
    margin: 5
  },
  contentStyle: {
    marginVertical: 5,
    marginHorizontal: 20
  },
  linkStyle: {
    marginVertical: 5,
    marginHorizontal: 20,
    color: 'blue'
  }
};
