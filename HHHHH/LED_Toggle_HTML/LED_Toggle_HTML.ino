//Follow us on other social media

//https://www.youtube.com/c/ZinTechIdeas
//https://www.facebook.com/zin.techideas.3
//https://www.instagram.com/zintechideas/
//https://twitter.com/Zintechideas
//https://zintechideas.ir/
#include <ESP8266WiFi.h>

int state = LOW;
int LED = LED_BUILTIN;
char on = LOW;
char off = HIGH;

const char* ssid = "zintechideas";//your-ssid
const char* password = "12345678";//your-password

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, off);

  Serial.print("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");  
  server.begin();  // Starts the Server
  Serial.println("Server started");

  Serial.print("IP Address of network: "); // Prints IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  
  if(request.indexOf("/LEDON") != -1)
  {
    digitalWrite(LED, on); // Turn ON LED
    state = on;
  }
  if(request.indexOf("/LEDOFF") != -1)
  {
    digitalWrite(LED, off); // Turn OFF LED
    state = off;
  }

/*------------------HTML Page Creation---------------------*/

  client.println("HTTP/1.1 200 OK"); // standalone web server with an ESP8266
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head>");
  client.println("<title>LED TOGGLE</title>");
  client.println("</head>");
  client.print("<body>");
  client.println("<header id=\"main-header\">");
  client.println("<h1>LED TOGGLE</h1>");
  client.println("<h4>by ZinTechIdeas</h4>");
  client.println("</header>");
   
  if(state == on)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }
  client.print("<br>");
  client.print("<br>");
  client.println("<a href=\"/https://www.facebook.com/profile.php?id=100088447571224\"\"><button class=\"button\">ON</button></a>");
  client.println("<a href=\"/LEDOFF\"\"><button class=\"button\">OFF</button></a>");
  client.print("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
