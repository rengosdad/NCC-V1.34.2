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

const char* ssid = "VNPT_hai";//your-ssid
const char* password = "khongcho";//your-password

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
  client.println("<style>");
  client.println(" .card1 {");
  client.println("  position: relative;");
  client.println("  background-color: #4462e7;");
  client.println("  width: 146px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 119, 255);");
  client.println(" }");
  client.println("h4 {");
  client.println("color: #ff0000;");
  client.println("font-family: Arial, sans-serif;");
  client.println("font-family: Arial, sans-serif;");
  client.println("font-style: italic;");
  client.println("font-weight: bold;");
  client.println("}");
  client.println("body {");
  client.println(" background-image: url('https://scontent.fdad1-3.fna.fbcdn.net/v/t39.30808-6/421049748_345091701782413_1150105188134522822_n.jpg?stp=dst-jpg_s960x960&_nc_cat=110&ccb=1-7&_nc_sid=5f2048&_nc_eui2=AeFs5XmFd6eqRgEQq12rY9LYT16wUvhjrntPXrBS-GOue3uo2Xa-welqXR5uyMt2MS2xeVDfcheM0oDx_xaVDsLN&_nc_ohc=gJzqyYEAlSMQ7kNvgGAg8eT&_nc_ht=scontent.fdad1-3.fna&cb_e2o_trans=t&oh=00_AfAGZMOQUNALKsSWMfiGUcwlDksm6yw1KJdXILiALQaH8A&oe=663D5B70');");
  client.println("background-repeat: no-repeat;");
  client.println("background-size: cover;");
  client.println("}");
  client.println("</style>");
  client.println("</head>");
  client.print("<body>");
  client.print("  ");
  client.println("<header id=\"main-header\">");
  client.println("<h1>LED TOGGLE</h1>");
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
  client.println("<a href=\"/LEDON\"\"><button class=\"button\">ON</button></a>");
  client.println("<a href=\"/https://www.facebook.com/profile.php?id=100088447571224\"\"><button class=\"button\">OFF</button></a>");
  client.println("<a href=\"https://www.facebook.com/profile.php?id=100088447571224\">Click here</a>");
  client.println(" <table>");
    client.println("   <tr>");
      client.println("   <div class=\"card1\">");
         client.println("  <div class=\"card-header\">This is a Header</div>");
         client.println("  <div class=\"card-body\"> ");
          client.println("  <h5 class=\"card-title\">Card title</h5>");
          client.println("   <h6><img src=\"https://scontent.fdad2-1.fna.fbcdn.net/v/t39.30808-6/439999415_1231552307822109_1136004389111044618_n.jpg?_nc_cat=101&ccb=1-7&_nc_sid=5f2048&_nc_ohc=plWPxOaMU5sQ7kNvgGsRm-b&_nc_ht=scontent.fdad2-1.fna&oh=00_AfCaexLebhzFnKwfhRxzcXu_KLORsaTmiQxKPwyI6Noq1Q&oe=663D6E2C\" width=\"250\" height=\"250\"> </h6> " );
          client.println(" </div>");
         client.println("   </div>");
      client.println(" </div>");
     client.println("  </tr>");
    client.println(" </table>");
  client.print("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
