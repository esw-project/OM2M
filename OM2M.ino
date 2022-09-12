
#include <HTTPClient.h>
#include <PubSubClient.h>
#include <WiFi.h>


HTTPClient http;

#define USERNAME "OnePlus 8"  // this is username of wifi
#define PASSWORD "12345678"  // this is password of wifi

#define onem2mid "!9KnkC"
#define onem2mpassword "07jEWt"

WiFiClient myclient;

void setup() {
  Serial.begin(115200);
  WiFi.begin(USERNAME, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  Serial.println("SUCCESSFUL");
  Serial.print("IP ADDRESS : ");
  Serial.println(WiFi.localIP());
  Serial.print("\n");
}


void loop() {

  static int count = 1;

  String server = "http://esw-onem2m.iiit.ac.in:443/~/in-cse/in-name/Team-18/Node-1/Data";
  http.begin(server);
  http.addHeader("X-M2M-Origin", "!9KnkC:07jEWt");
  http.addHeader("Content-Type", "application/json;ty=4");
  http.addHeader("Content-Length", "100");
//  String req_data = String() + "{\"m2m:cin\": {" + "\"con\": \"" + datai + "\"," + "\"cnf\": \"text\"" + "}}";
  String req_data1 = String() + "{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": \"" + String(count) + "\"}}";
  
  int code = http.POST(req_data1);
  count++;
  Serial.println(code);
  http.end();
  delay(1000);
}
