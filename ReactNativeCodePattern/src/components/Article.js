import React from 'react';
import { View, Linking, TouchableHighlight } from 'react-native';
import { Text, Button, Card, Divider } from 'react-native-elements';
import { Actions } from 'react-native-router-flux';
import moment from 'moment';

export default class Article extends React.Component {
  render() {
    const {
      title,
      text,
      publication_date,
      main_image_url,
      host,
      enriched_text,
      url
    } = this.props.article;
    const { noteStyle, linkStyle, featuredTitleStyle } = styles;
    const time = moment(publication_date || moment.now()).fromNow();

    return (
      <Card title={title} >
        <Text style={{ marginBottom: 20 }}>
          {text || 'Read more..'}
        </Text>
        <Divider style={{ backgroundColor: '#dfe6e9' }} />

        <TouchableHighlight onPress={() => Actions.insights({enriched_text: enriched_text})} >
          <Text style={noteStyle}>More analysis from IBM Watson Discovery</Text>
        </TouchableHighlight>

        <Divider style={{ backgroundColor: '#dfe6e9' }} />
        <TouchableHighlight onPress={() => Linking.openURL(url)} >
          <View style={{ flexDirection: 'row', justifyContent: 'space-between' }}>
            <Text style={noteStyle}>{host.toUpperCase()}</Text>
            <Text style={noteStyle}>{time}</Text>
          </View>
        </TouchableHighlight>
      </Card>
    );
  }
}

const styles = {
  noteStyle: {
    margin: 10,
    color: '#b2bec3',
    fontSize: 10
  },
  linkStyle: {
    margin: 5,
    color: 'blue',
    fontSize: 10
  }
};
