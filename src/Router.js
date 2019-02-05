// Define the different routes a user can visit
import React from 'react';
import { Scene, Router } from 'react-native-router-flux';

import ArticleList from './components/ArticleList';
import Insights from './components/Insights';

// React Native app routing:
// (1) list articles from Discovery
// (2) view of Watson Discovery results (sentiment, keywords, concepts)

const RouterComponent = () => {
  return (
    <Router>
      <Scene key="root" hideNavBar>
        <Scene key="main">
          <Scene key="list" component={ArticleList} title="Articles" initial />
          <Scene key="insights" component={Insights} title="Insights" />
        </Scene>
      </Scene>
    </Router>
  );
};

export default RouterComponent;
