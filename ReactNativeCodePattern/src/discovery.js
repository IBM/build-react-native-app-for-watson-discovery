import GLOBALS from '../Globals';

export async function getDiscovery(keyword) {
  // use Discovery Query Language
  const url_dql = `https://gateway.watsonplatform.net/discovery/api/v1/environments/system/collections/news-en/query?version=2018-08-01&aggregation=filter%28enriched_title.entities.type%3A%3ACompany%29.term%28enriched_title.entities.text%29.timeslice%28crawl_date%2C1day%29.term%28enriched_text.sentiment.document.label%29&filter=IBM&highlight=true&passages.count=5&query=${keyword}`;

  let result = await fetch(url_dql, {
    method: 'GET',
    headers: {
      Accept: 'application/json',
      'Content-Type': 'application/json',
      'Authorization': 'Basic '+btoa(`${GLOBALS.WATSON_DISCOVERY_CREDENTIALS}`)
    }
  }).then(response => response.json());

  console.log(result);
  return result.results;
}
