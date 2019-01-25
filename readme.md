# README

# Build a cross-platform mobile app to search company news and gain insights
Get started building a cross-platform mobile app using React Native to fetch news on a company and gain insights using Watson Discovery.

Create a cross-platform mobile app that fetches news for a specific company. The application uses Watson Discovery to get news articles with sentiment, keywords, and related concepts. This application is easily customizable and provides a starting point to use Watson Discovery in your own React Native applications.

Following completion of this pattern, the developer will understand how to:
* Create a cross-platform mobile application using React Native
* Use Watson Discovery to detect sentiment and keywords for articles
* Use Watson Discovery to find additional, related news articles for each associated keyword

## Quick start
  1. Sign up for IBM Cloud. Then sign up for Watson Discovery. Copy the API Key under Credentials for Watson Discovery.
  2. In Globals.js, add your Watson Discovery API Key in this format: apikey:YOUR_API_KEY
  3. Open a terminal, and then run
    `> npm install`
    `> react-native run-ios`

TBD: Architecture Diagram

## Flow
1. A Discovery News collection is created.
2. The user interacts with Discovery News via the React Native app UI.
3. Initial load of app pull up recent, relevant articles for a company.
4. User can click on insights to get sentiment, keywords, and concepts from Discovery for that article.
5. User is able to click on any of these Discovery sentiment, keywords, and/or concepts results to make an additional query into Discovery.

## Included components
* [IBM Watson Discovery](https://www.ibm.com/watson/developercloud/discovery.html): A cognitive search and content analytics engine for applications to identify patterns, trends, and actionable insights. Extract meta-data from returned content such as concepts, keywords, and, sentiment, using natural language understanding.

## Featured technologies
* [React Native](https://facebook.github.io/react-native/): React Native lets you build mobile apps using only JavaScript. It uses the same design as [React](https://reactjs.org/), letting you compose a rich mobile UI from declarative components.

# Watch the Video
TBD

# Steps to run locally

### 1. Sign up for IBM Cloud
<!-- TODO: need link with tracking for IBM Cloud signup -->

### 2. Create Watson services with IBM Cloud (Watson Discovery)
* [**Watson Discovery**](https://console.ng.bluemix.net/catalog/services/discovery)

### 3. Configure credentials

The credentials for IBM Cloud services (Watson Discovery), can be found in the ``Services`` menu in IBM Cloud,
by selecting the ``Service Credentials`` option for the service.

In the Globals.js file, add your Watson Discovery username and password in this format: username:password

### 4. Install Node.js
1. Install [Node.js](https://nodejs.org/en/)

### 5. Clone the repo

Clone the `ReactNativeCodePattern` locally. In a terminal, run:

```
$ git clone https://github.ibm.com/tmarkiewicz/ReactNativeCodePattern
```

### 6. Install dependencies
  run `> npm install` in a terminal

### 7. Run the application using the iOS Simulator (Xcode on a Mac is required)
  run `> react-native run-ios` in a terminal

### 8. View the Watson Discovery dashboard (optional)
![Image of Watson Discovery dashboard](watson-discovery-news-collection-dashboard.png)

# Links
* [Watson Discovery Getting Started Tutorial](https://console.bluemix.net/docs/services/discovery/getting-started.html#getting-started-tutorial)
* [Watson Discovery API docs](https://console.bluemix.net/apidocs/discovery)

# License
[Apache 2.0](LICENSE)
