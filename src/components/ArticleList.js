import React from 'react';
import { View, FlatList } from 'react-native';
import { getDiscovery } from '../discovery';
import Article from './Article';

export default class ArticleList extends React.Component {
  constructor(props) {
    super(props);
    this.state = { articles: [], refreshing: true };
    this.fetchNews = this.fetchDiscovery.bind(this);
  }

  componentDidMount() {
    this.fetchDiscovery();
  }

  fetchDiscovery() {
    getDiscovery(this.props.keyword || 'IBM')
      .then(articles => this.setState({ articles, refreshing: false }))
      .catch(() => this.setState({ refreshing: false }));
  }

  handleRefresh() {
    this.setState({refreshing: true}, () => this.fetchDiscovery());
  }

  render() {
    return (

      <View>
        {/* https://medium.com/react-native-development/how-to-use-the-flatlist-component-react-native-basics-92c482816fe6 */}
        <FlatList
          data={this.state.articles}
          renderItem={({ item }) => <Article article={item} />}
          keyExtractor={item => item.url}
          refreshing={this.state.refreshing}
          onRefresh={this.handleRefresh.bind(this)}
        />
      </View>

    );
  }
}
