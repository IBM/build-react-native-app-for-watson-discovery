# Project Structure

Below is a general overview of the most important directories and files in the project.

```
├── android # All the native Android code for the project
├── ios # All the native iOS code for the project
├── src # Folder for the custom source files
│   ├── components # The shared, functional components are stored here
│   │   ├── Article.js # Displays the individual cards as requested by ArticleList.js
│   │   ├── ArticleList.js # Calls discovery.js and displays the returned results as a list of cards for the articles
│   │   └── Insights.js # Displays the enriched text (keywords, sentiment) returned by Discovery and displays on the screen
│   ├── discovery.js # Makes the request to the Watson Discovery API and returns the results
│   ├── Router.js # Defines the different routes a user can visit
├── App.js # Loads the main class for the app and sets the routing
├── app.json # Config file containing the app’s name
├── Globals.js # Stores the Watson Discovery API credentials as a constant
├── index.js # The entry point for the application
├── package.json # Config file containing dependencies and config
```

For a further overview of React Native and its project structure, please visit [Dissecting React Native](https://developer.ibm.com/articles/dissecting-react-native/).
