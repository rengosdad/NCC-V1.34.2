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

const char* ssid = "Helllo";//yoiur-ssid
const char* password = "12344321";//your-password

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
   client.println("  <style type=\"text/css\">");
    client.println("    #test{");
          client.println("  overflow-x:hidden;");
         client.println("   overflow-y:auto;");
       client.println(" }");
   client.println(" </style>");
  client.println("<style>");

client.println(".card {");
 client.println(" width: 450px;");
 client.println(" height: 400px;");
 client.println(" overflow: hidden;");
client.println("}");

client.println(".card-content {");
 client.println(" height: 75%;");
 client.println(" overflow-y: auto;");
 client.println(" padding: 10px;");
 
client.println("}");

client.println(".card-title {");
  client.println("font-size: 24px;");
 client.println(" margin-bottom: 10px;");
client.println("}");

client.println(".card-text {");
client.println("  font-size: 16px;");
 client.println(" line-height: 1.5;");
client.println("}");

client.println(".card-scroll {");
client.println("  height: 100%;");
 client.println(" overflow-y: auto;");
client.println("}");

  client.println(" .card-image {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");
  client.println(" .card1 {");
  client.println("  position: relative;");
  client.println("  background-color: #4462e7e0;");
  client.println("  width: 120px;");
  client.println("  height: 220px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);");
  client.println(" }");

  client.println(" .card-image2 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img2 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");
  
  client.println(" .card2 {");
  client.println("  position: relative;");
  client.println("   background-color: #5aec46d1;");
  client.println("  width: 120px;");
  client.println("  height: 220px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

   client.println(" .card-image4 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img4 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");
  
  client.println(" .card4 {");
  client.println("  position: relative;");
  client.println("  background-color: #f1dc46d6;");
  client.println("  width: 120px;");
  client.println("  height: 220px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

  client.println(" .card5 {");
  client.println("  position: relative;");
  client.println("     background-color: #ec4646d9;");
  client.println("  width: 120px;");
  client.println("  height: 220px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

  client.println(" .card-image5 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

  client.println(" .card6 {");
  client.println("  position: relative;");
    client.println(" background-image: url('https://digwallpapers.com/wallpapers/full/f/a/e/79050-3840x2160-rem-re-zero-wallpaper-photo-desktop-4k.jpg');");
  client.println(" background-size: 2080px 1070px;");
  //client.println("     background-color: #4adbdbd9;");
  client.println("  width: 1840px;");
  client.println("  height: 560px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 80px rgb(0 169 255);;");
  client.println(" }");

  client.println(" .card-image6 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

  client.println(" .card7 {");
  client.println("  position: relative;");
  client.println("     background-color: #6f47ebd9;");
  client.println("  width: 220px;");
  client.println("  height: 280px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 3px 17px 150px rgb(0 244 255);;");
  client.println(" }");

  client.println(" .card-image7 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

    client.println(" .card8 {");
  client.println("  position: relative;");
  client.println("     background-color: #dd5050db;");
  client.println("  width: 790px;");
  client.println("  height: 280px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 3px 17px 150px rgb(0 244 255);;");
  client.println(" }");

  client.println(" .card-image8 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

  client.println(" .card12 {");
  client.println("  position: relative;");
  client.println("     background-color: #ec8b46d9;");
  client.println("  width: 120px;");
  client.println("  height: 220px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

  client.println(" .card-image12 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

  client.println(" .card13 {");
  client.println("  position: relative;");
client.println(" background-image: url('https://c.wallhere.com/photos/4f/49/anime_Re_Zero_Rem_Re_Zero_Rem_Re_Zero_Kara_Hajimeru_Isekai_Seikatsu-1664731.jpg!d');");
  client.println(" background-size: cover;");
  client.println("  width: 1840px;");
  client.println("  height: 1280px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
 // client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
 client.println("box-shadow: 0 50px 80px rgb(0 169 255);");
  client.println(" }");

  client.println(" .card-image13 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

  client.println(" .card54 {");
  client.println("  position: relative;");
  client.println("     background-color: #ec4646d9;");
  client.println("  width: 1840px;");
  client.println("  height: 1520px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

  client.println(" .card-image54 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img5 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

    client.println(" .card15 {");
  client.println("  position: relative;");
  client.println("     background-color: #ec4646d9;");
  client.println("  width: 120px;");
  client.println("  height: 220px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  //client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

  client.println(" .card-image15 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img15 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

      client.println(" .card16 {");
  client.println("  position: relative;");
  client.println("     background-color: #ec4646d9;");
  client.println("  width: 1220px;");
  client.println("  height: 1020px;");
  client.println("  padding: 120px;");
  client.println("  border-radius: 20px;");
  client.println("  box-shadow: 0 50px 100px rgb(0, 255, 157);;");
  client.println(" }");

  client.println(" .card-image16 {");
  client.println("  border-radius: 20px;");
  client.println(" display: flex;");
  client.println(" justify-content: center;");
  client.println("}");
  client.println(".card-image img15 {");
  client.println(" display: block;");
  client.println("margin: 0 auto;");
  client.println("}");

  client.println(" .card14 {");
  client.println("  width: 120px;");
  client.println("  height: 1120px;");
  client.println("  padding: 120px;");
  client.println(" }");

  // client.println(" .card14 {");
  client.println("  width: 1158px;");
  client.println("  height: 820px;");
  client.println("     background-color: #ec4646d9;");
  client.println(" }"); 

 
   client.println(" .card3 {");
  client.println("  width: 58px;");
  client.println("  height: 220px;");
  client.println(" }");

   client.println(" .card19 {");
  client.println("  width: 58px;");
  client.println("  height: 220px;");
  client.println(" }");
  
   client.println(" .card9 {");
  client.println("  width: 35px;");
  client.println("  height: 220px;");
  client.println(" }");

  client.println(" .card10 {");
  client.println("  width: 30px;");
  client.println("  height: 220px;");
  client.println(" }");
  
  client.println(" .card11 {");
  client.println("  width: 30px;");
  client.println("  height: 70px;");
  client.println(" }");
  
    client.println(" .card18 {");
  client.println("  width: 30px;");
  client.println("  height: 50px;");
  client.println(" }");
  
   client.println(" h1 {");
   client.println("  position: relative;");
   client.println("  text-align: center;");
   client.println(" color: #82e6f3;");
   client.println(" font-size: 50px;");
  client.println(" font-family: \"Cormorant Garamond\", serif, Comic;");
  client.println("}");

   client.println(" h8 {");
  // client.println("  position: relative;");
  // client.println("  text-align: center;");
  // client.println(" color: #82e6f3;");
   client.println(" font-size: 30px;");
  client.println(" font-family: Calibri ;");
  client.println("}");

  client.println("h4 {");
  client.println("color: #ff0000;");
  client.println("font-family: Arial, sans-serif;");
  client.println("font-family: Arial, sans-serif;");
  client.println("font-style: italic;");
  client.println("font-weight: bold;");
  client.println("}");
  
  client.println("body {");
  client.println(" background-image: url('https://lh5.googleusercontent.com/dbx7I_k7yBSpDaqwxeh1KVuneaA9CWlSPdjcCY6pneE_XV3Yeia3FcAjJ62usYOpbQEQdm_w0BsXUEUn_7gUmZXwXHCeQhyVcJbWsHjLluJ4g0uzV8bm7puxY3wtMWikhw=w1280');");
  client.println("background-repeat: no-repeat;");
  client.println("background-size: cover;");
  client.println("}");
  
  client.println("</style>");
  client.println("</head>");
  client.print("<body>");
  client.print("  ");
  client.println("<header id=\"main-header\">");
  client.println("<h1>  NCC HYDROPOWER PLANT MODEL  </h1>");
  client.println("</header>");



  client.println("   <div class=\"card13\">");
  //client.println("  <div class=\"card-header6\">This is a Header</div>");
  client.println("  <div class=\"card-body13\"> ");
client.println(" <div class=\"card-image13\" style=\"display: flex; justify-content: center;\">");
  
  client.println(" <table>");
  
  client.println("<td>");
  client.println("   <div class=\"card14\">");
  //client.println("  <div class=\"card-header6\">This is a Header</div>");
  client.println("  <div class=\"card-body14\"> ");
client.println(" <div class=\"card-image14\" style=\"display: flex; justify-content: center;\">");
client.println(" <table>");
client.println("<tr>");
client.println("<th>");
      client.println("   <div class=\"card15\">");
  client.println("  <div class=\"card-header15\">This is a Header</div>");
  client.println("  <div class=\"card-body15\"> ");
  client.println(" <div class=\"card-image15 \" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://scontent.fdad1-1.fna.fbcdn.net/v/t39.30808-6/439866635_1232484124395594_1659010615677167927_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=5f2048&_nc_ohc=b_tqcPpJwN8Q7kNvgGOBwGe&_nc_ht=scontent.fdad1-1.fna&oh=00_AfCGi0j7duB3TZTudJ2lssqaZdL1dwS9bpYc2-yXt1rkBA&oe=663F5B70\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  client.println("</th>");
  client.println("  </tr>");
  
   client.println("<td>");
client.println("   <div class=\"card18\">");
  client.println(" </div>");
  client.println("</td>");
  
   client.println(" <tr>");
   client.println("<th>");
      client.println("   <div class=\"card15\">");
  client.println("  <div class=\"card-header15\">This is a Header</div>");
  client.println("  <div class=\"card-body15\"> ");
  client.println(" <div class=\"card-image15 \" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://scontent.fdad1-1.fna.fbcdn.net/v/t39.30808-6/439866635_1232484124395594_1659010615677167927_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=5f2048&_nc_ohc=b_tqcPpJwN8Q7kNvgGOBwGe&_nc_ht=scontent.fdad1-1.fna&oh=00_AfCGi0j7duB3TZTudJ2lssqaZdL1dwS9bpYc2-yXt1rkBA&oe=663F5B70\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
      client.println("</th>");
 client.println("   </tr>");

      client.println(" </table>");
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  client.println("</td>");

 client.println("<td>");
client.println("   <div class=\"card11\">");
  client.println(" </div>");
  client.println("</td>");

  client.println("<td>");
      client.println("   <div class=\"card16\">");
  client.println("  <div class=\"card-header16\">This is a Header</div>");
  client.println("  <div class=\"card-body16\"> ");
  client.println(" <div class=\"card-image16 \" style=\"display: flex; justify-content: center;\">");
 client.println("   <h8>The Pelton wheel is a water turbine that creates momentum. It was invented by Lester Allan Pelton in the 1870s. The Pelton wheel derives its quantity from the momentum of the water's movement, as opposed to the amount of dead matter in the water when the water wheel exceeds its traditional capacity. Many variations of pulse turbines existed before Pelton's design, but they were more efficient than Pelton's design. Water left behind by wheels often stagnates at high speeds, carrying a lot of kinetic energy to the wheels. The shape of the Pelton's paddle is designed so that when the rim runs at half the speed of the water jet, the water leaves the wheel at a very slow rate; His design therefore takes full advantage of the entire oscillating energy of the water - allowing for a very efficient turbine. Lester Allan Pelton was born in Vermillion, Ohio in 1829. In 1850, he traveled overland to California, participating in the gold rush. Pelton sold fish he caught in the Sacramento River.[3] In 1860, he moved to Camptonville, a center of mining activity. At this time, many mining operations powered by steam engines consumed large quantities of wood for their fuel. Some water wheels were used in larger rivers, but they were ineffective in the smaller streams found near mines. Pelton was working on a design for a water wheel that would work with the relatively small flows found in these streams. In the mid-1870s, Pelton developed a wooden prototype of his new wheel. In 1876, Miners Foundry in Nevada City was approached to build the first commercial models in iron. The first Pelton wheel was installed at the Mayflower mine in Nevada City in 1878.. The efficiency advantages of Pelton's invention were quickly recognized and his products were soon in high demand. By the mid-1880s, the Miners Foundry was unable to meet demand, and in 1888 Pelton sold the rights to his name and the patent for his invention to the Pelton Water Wheel Company of San Francisco. The company established a factory at 121/123 Main Street in San Francisco. The Pelton Water Wheel Company manufactured a large number of Pelton wheels in San Francisco that were shipped worldwide. In 1892, the Company added a branch on the east coast at 143 Liberty Street in New York City. By 1900, more than 11,000 turbines were in use. In 1914, the company moved to new, larger manufacturing facilities at 612 Alabama Street in San Francisco. In 1956, the company was acquired by Baldwin-Lima-Hamilton, which ended production of Pelton wheels.</h8> " );  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
 client.println("</td>");
 
      client.println(" </table>");
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");



   client.print("<br>");

 client.println("<td>");
client.println("   <div class=\"card11\">");
  client.println(" </div>");
  client.println("</td>");

  client.print("<br>"); 

  
    client.println(" <table>");
  client.println(" <td>");
  client.println("   <div class=\"card6\">");
  //client.println("  <div class=\"card-header6\">This is a Header</div>");
  client.println("  <div class=\"card-body6\"> ");
  client.println(" <div class=\"card-image6\" style=\"display: flex; justify-content: center;\">");
  client.println(" <table>");
  client.println("<td>");
    client.println("   <div class=\"card7\">");
   // client.println("  <div class=\"card-header7\">This is a Header</div>");
    client.println("  <div class=\"card-body7\"> ");
    client.println(" <div class=\"card-image7\" style=\"display: flex; justify-content: center;\">");
      client.println("   <h6><img src=\"https://scontent.fdad2-1.fna.fbcdn.net/v/t39.30808-6/436315459_1236262430684430_4936646708882636307_n.jpg?stp=dst-jpg_p552x414&_nc_cat=107&ccb=1-7&_nc_sid=5f2048&_nc_ohc=yk_bPKbEPi0Q7kNvgFqWObv&_nc_ht=scontent.fdad2-1.fna&oh=00_AYCPJun1Rz01IzCNr9xQ5gBUBLn3FocuorttnzTRP9DesQ&oe=6647C215\" width=\"300\" height=\"270\"> </h6> " );
    client.println("    </div>");
    client.println(" </div>");
    client.println("   </div>");
    client.println(" </div>");
          
          
   client.println("<td>");
          
client.println("   <div class=\"card10\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");
       client.println("<td>");
    client.println("   <div class=\"card7\">");
   // client.println("  <div class=\"card-header7\">This is a Header</div>");
    client.println("  <div class=\"card-body7\"> ");
    client.println(" <div class=\"card-image7\" style=\"display: flex; justify-content: center;\">");
    client.println("   <h6><img src=\"https://scontent.fdad1-3.fna.fbcdn.net/v/t39.30808-6/440351651_1236261977351142_6422985052991169919_n.jpg?stp=dst-jpg_s600x600&_nc_cat=104&ccb=1-7&_nc_sid=5f2048&_nc_ohc=5bbj1mQ-KaIQ7kNvgGPlJm4&_nc_ht=scontent.fdad1-3.fna&oh=00_AYCYtHE9F7AVAI8F0nnTC82wlV73e3N-8vjdOwHvdj4Zhw&oe=6647B9F4\" width=\"300\" height=\"270\"> </h6> " );
    client.println("    </div>");
    client.println(" </div>");
    client.println("   </div>");
    client.println(" </div>");
          client.println("</td>");
          client.println("<td>");
          
client.println("   <div class=\"card9\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");
                 client.println("<td>");
                     client.println("   <div class=\"card8\">");
  //  client.println("  <div class=\"card-header8\">This is a Header</div>");
    client.println("  <div class=\"card-body8\"> ");
    client.println(" <div class=\"card-image8\"style=\"display: flex; justify-content: center;\">");
    client.println(" <table>");
    client.println("<td>");

    client.println("  <h2 class=\"card-title\">WEBSEVER</h2>");
    client.println(" <div class=\"card\">");
   client.println("<div class=\"card-content\">");
    client.println(" <div class=\"card-text\">");
   
   client.println("  <p class=\"card-text\">body {");
      client.println("  <p class=\"card-text\">background-color: #DDEBAF;");
        client.println("  <p class=\"card-text\">font-family: Arial, sans-serif;");
          client.println("  <p class=\"card-text\">margin: 0;");
            client.println("  <p class=\"card-text\">padding: 0;");
              client.println("  <p class=\"card-text\"> }");
                client.println("  <p class=\"card-text\">.data-container  { ");
                  client.println("  <p class=\"card-text\"> display: flex;");
                    client.println("  <p class=\"card-text\"> justify-content: space-between;");
                      client.println("  <p class=\"card-text\">width: 80%;");
                        client.println("  <p class=\"card-text\">margin: auto;");
                          client.println("  <p class=\"card-text\">padding: 20px;");
                            client.println("  <p class=\"card-text\">background-color: #FFF;");
      client.println("  <p class=\"card-text\">box-shadow: 0 2px 20px rgba(0, 0, 0,0.1);");
        client.println("  <p class=\"card-text\">border-radius: 10px;");
          client.println("  <p class=\"card-text\"> } ");

            client.println("  <p class=\"card-text\">.data-item { ");
              client.println("  <p class=\"card-text\"> text-align: center;");
                client.println("  <p class=\"card-text\">  } ");

                  client.println("  <p class=\"card-text\">.data-item h2 { ");
                    client.println("  <p class=\"card-text\"> font-size: 18px;");
                      client.println("  <p class=\"card-text\"> font-weight: bold;");
                        client.println("  <p class=\"card-text\"> margin-bottom: 10px;");
                          client.println("  <p class=\"card-text\"> color: #F709A2;");
                            client.println("  <p class=\"card-text\"> } ");

                              client.println("  <p class=\"card-text\">.data-item p {");
                                client.println("  <p class=\"card-text\"> font-size: 22px;");
                                  client.println("  <p class=\"card-text\"> font-weight: bold;");
                                    client.println("  <p class=\"card-text\"> color: #07F924;");
                                      client.println("  <p class=\"card-text\"> } ");



                                        client.println("  <p class=\"card-text\">.data-head {");
                                          client.println("  <p class=\"card-text\"> margin: auto;");
                                            client.println("  <p class=\"card-text\">width: 50%;");
                                              client.println("  <p class=\"card-text\">text-align: center;");
      client.println("  <p class=\"card-text\">font-size: 28px;");
        client.println("  <p class=\"card-text\">font-weight: bold;");
           client.println("  <p class=\"card-text\">             color: #3018E2;");
      client.println("  <p class=\"card-text\">margin: 50px auto;");
        client.println("  <p class=\"card-text\">padding: 20px;");
          client.println("  <p class=\"card-text\">background-color: #FFF;");
            client.println("  <p class=\"card-text\">box-shadow: 0 5px 20px rgba(0, 0, 0, 0.1);");
              client.println("  <p class=\"card-text\">border-radius: 20px;");




client.println("  <p class=\"card-text\"> } ;");



                  client.println("  <p class=\"card-text\"> \"style\" ;");
                    client.println("  <p class=\"card-text\"> \"head\";");
                      client.println("  <p class=\"card-text\">\"body\";");

                        client.println("  <p class=\"card-text\">\"div class=\"data-head\">AAAAAAAAAA</div\";");

               
                          client.println("  <p class=\"card-text\">    \"div\";");
                            client.println("  <p class=\"card-text\">  \"div class=\"data-container \";");
                              client.println("  <p class=\"card-text\">\"div class=\"data-item\">;");
                                  client.println("  <p class=\"card-text\"> \"h2 TGTG h2\";");
                                  client.println("  <p class=\"card-text\"> \"p class=\"value\" id=\"cap nhat\"18 ;/p\";   ");        
                                  client.println("  <p class=\"card-text\">\"div\"");
    
                                    client.println("  <p class=\"card-text\">           \"div class=\"data-item\"\";");
                                      client.println("  <p class=\"card-text\"> \"h2 CCC /h2\";");
                                        client.println("  <p class=\"card-text\"> \"p class=\"value\" id=\"cong xuat\" 18 ;/p\";");
                                        client.println("  <p class=\"card-text\">\"/div\";");
                                          client.println("  <p class=\"card-text\">   \"div\";");

                                            client.println("  <p class=\"card-text\">  \"div class=\"data-container \"\";");
                                              client.println("  <p class=\"card-text\">\"div class=\"data-item\"\";");
                                                client.println("  <p class=\"card-text\">\"h2 DDD /h2\";");
                                                  client.println("  <p class=\"card-text\"> \"p class=\"value\" id=\"dong dien\" 18 ; /p\"; ");
                                                  client.println("  <p class=\"card-text\">\" div \";");
                                                    client.println("  <p class=\"card-text\">\"div class=\"data-item\"\";");
                                                      client.println("  <p class=\"card-text\">\"h2 HHH h2\";");
                                                        client.println("  <p class=\"card-text\">\"p class=\"value\" id=\"hieu dien the\" 10% /p\";");
                                                        client.println("  <p class=\"card-text\">\"div\";");
                                                          client.println("  <p class=\"card-text\">    \"div\";");

                                                            client.println("  <p class=\"card-text\">\"div class=\"data-container \"\";");
                                                              client.println("  <p class=\"card-text\"> \"div class=\"data-item\"\";");
                                                                client.println("  <p class=\"card-text\"> \"h2 TTT /h2\";");
                                                                  client.println("  <p class=\"card-text\"> \"p class=\"value\" id=\"toc do\" 18 ; /p\"     ;");      
                                                                  client.println("  <p class=\"card-text\">\"div\";");
                                                                    client.println("  <p class=\"card-text\">\"div class=\"data-item\"\";");
                                                                      client.println("  <p class=\"card-text\">\"h2 LLL h2\";");
                                                                        client.println("  <p class=\"card-text\">\"p class=\"value\" id=\"luu luong\" 18 ; p\";");
                                                                        client.println("  <p class=\"card-text\">\"div\";");

    
                                                                          client.println("  <p class=\"card-text\">  \"div\";");



                                                                         // client.println("<p class=\"card-text\">");
      client.println("  \"p class=\"card-text\">  div class=\"data-container \"\"");
        client.println("  <p class=\"card-text\"> \"div class=\"data-item\"\"");
          client.println("  <p class=\"card-text\">\"h2 Áp xuất nước h2\"");
            client.println("  <p class=\"card-text\">\"p class=\"value\" id=\"ap xuat\" 10% p\"");
            client.println("  <p class=\"card-text\"> \"div\"");
    
              client.println("  <p class=\"card-text\">\"div class=\"data-item\"\"");
                client.println("  <p class=\"card-text\"> \"h2 Độ cao cột nước h2 \"");
                  client.println("  <p class=\"card-text\">\"p class=\"value\" id=\"do cao cot nuoc\" 10% p\"");
      client.println("  <p class=\"card-text\">\"div\"");
        client.println("  <p class=\"card-text\">    \"div\"");

        

          client.println("  <p class=\"card-text\"> !-- the scripts for products you want to access must be added-->");

            client.println("  <p class=\"card-text\"> script src=\"https://www.gstatic.com/firebasejs/8.6.8/firebase-app.js\" /script\");");

              client.println("  <p class=\"card-text\"> script src=\"https://www.gstatic.com/firebasejs/8.6.8/firebase-database.js\" /script\"");
                

                client.println("  <p class=\"card-text\">\"script type=\"module\"\"");
    // Import the functions you need from the SDKs you need
    client.println("  <p class=\"card-text\"> import { initializeApp } from \"https://www.gstatic.com/firebasejs/9.20.0/firebase-app.js\";");
    // TODO: Add SDKs for Firebase products that you want to use
    // https://firebase.google.com/docs/web/setup#available-libraries

    // Your web app's Firebase configuration here (Do not use the existing configuration)
    client.println("  <p class=\"card-text\">  const firebaseConfig = {");
        client.println("  <p class=\"card-text\">     apiKey: \"AIzaSyB8NcIufAajrHaHlB_ANVw7kFkWqiob_7c\";");
      client.println("  <p class=\"card-text\">    authDomain: \"thuydienmini-23984.firebaseapp.com\",");
        client.println("  <p class=\"card-text\">   databaseURL: \"https://thuydienmini-23984-default-rtdb.firebaseio.com\",");
          client.println("  <p class=\"card-text\">  projectId: \"thuydienmini-23984\",");
            client.println("  <p class=\"card-text\">  storageBucket: \"thuydienmini-23984.appspot.com\",");
              client.println("  <p class=\"card-text\">  messagingSenderId: \"24024317744\",");
                client.println("  <p class=\"card-text\"> appId: \"1:24024317744:web:475277d355ddeb2dcd92f5\",");
                  client.println("  <p class=\"card-text\"> measurementId: \"G-E61P5NX23B\",");
                    client.println("  <p class=\"card-text\"> };");

    // Initialize Firebase
    client.println("  <p class=\"card-text\"> firebase.initializeApp(firebaseConfig);");


    // getting reference to the database
    client.println("  <p class=\"card-text\"> var database = firebase.database();");

    //getting reference to the data we want
    client.println("  <p class=\"card-text\">  var dataRef1 = database.ref('ap xuat');");
    client.println("  <p class=\"card-text\"> var dataRef2 = database.ref('cap nhat');");
      client.println("  <p class=\"card-text\">    var dataRef3 = database.ref('cong xuat');");
        client.println("  <p class=\"card-text\"> var dataRef4 = database.ref('do cao cot nuoc');");
          client.println("  <p class=\"card-text\">   var dataRef5 = database.ref('dong dien');");
            client.println("  <p class=\"card-text\"> var dataRef6 = database.ref('hieu dien the');");
              client.println("  <p class=\"card-text\">    var dataRef7 = database.ref('toc do');");
                client.println("  <p class=\"card-text\"> var dataRef8 = database.ref('luu luong');");
    //fetch the data
    client.println("  <p class=\"card-text\"> dataRef1.on('value', function(getdata1){");
    client.println("  <p class=\"card-text\"> var ax = getdata1.val();");
      client.println("  <p class=\"card-text\"> document.getElementById('ap xuat').innerHTML = ax + \" KPa\";");
        client.println("  <p class=\"card-text\">})");

          client.println("  <p class=\"card-text\"> dataRef2.on('value', function(getdata2){");
    client.println("  <p class=\"card-text\"> var cn = getdata2.val();");
      client.println("  <p class=\"card-text\"> document.getElementById('cap nhat').innerHTML = cn + "";");
      client.println("  <p class=\"card-text\">})");
    client.println("  <p class=\"card-text\">dataRef3.on('value', function(getdata1){");
  client.println("  <p class=\"card-text\"> var cx = getdata1.val();");
      client.println("  <p class=\"card-text\">document.getElementById('cong xuat').innerHTML = cx + \" mW\";");
      client.println("  <p class=\"card-text\"> })");

    client.println("  <p class=\"card-text\"> dataRef4.on('value', function(getdata2){");
    client.println("  <p class=\"card-text\"> var dc = getdata2.val();");
      client.println("  <p class=\"card-text\"> document.getElementById('do cao cot nuoc').innerHTML = dc + \" m\";");
      client.println("  <p class=\"card-text\"> })");
    client.println("  <p class=\"card-text\">dataRef5.on('value', function(getdata1){");
    client.println("  <p class=\"card-text\">   var dd = getdata1.val();");
      client.println("  <p class=\"card-text\"> document.getElementById('dong dien').innerHTML = dd + \" mA\";");
      client.println("  <p class=\"card-text\">  })");

    client.println("  <p class=\"card-text\">  dataRef6.on('value', function(getdata2){");
    client.println("  <p class=\"card-text\">   var dt = getdata2.val();");
      client.println("  <p class=\"card-text\">   document.getElementById('hieu dien the').innerHTML = dt + \" V\";");
      client.println("  <p class=\"card-text\">  })");
    client.println("  <p class=\"card-text\">dataRef7.on('value', function(getdata1){");
  client.println("  <p class=\"card-text\">   var td = getdata1.val();");
      client.println("  <p class=\"card-text\">   document.getElementById('toc do').innerHTML = td + \" v/p\";");
      client.println("  <p class=\"card-text\">  })");

    client.println("  <p class=\"card-text\">  dataRef8.on('value', function(getdata2){");
    client.println("  <p class=\"card-text\"> var ll = getdata2.val();");
      client.println("  <p class=\"card-text\"> document.getElementById('luu luong').innerHTML = ll + \" l/h\";");
      client.println("  <p class=\"card-text\"> })");

    client.println("  <p class=\"card-text\"></script>");

  client.println("  <p class=\"card-text\"></body>");
client.println("  <p class=\"card-text\"></p></html>");

  
    client.println(" </div>");
   client.println("</div>");
 client.println("</div>");
 client.println("</td>");


client.println("<td>");
client.println("   <div class=\"card9\">");
  client.println(" </div>");
  client.println("</td>");

 client.println("<td>");
 client.println("  <h2 class=\"card-title\">FASEBASE</h2>");
    client.println(" <div class=\"card\">");
   client.println("<div class=\"card-content\">");
   client.println("  <p class=\"card-text\">#include \"HX711.h\" ");
client.println("  <p class=\"card-text\">#include <LiquidCrystal_I2C.h>");
client.println("  <p class=\"card-text\">LiquidCrystal_I2C lcd(0x27,16,2);  LCD 16x02, địa chỉ I2C là 0X27");

 client.println("  <p class=\"card-text\"> HX711 circuit wiring");
client.println("  <p class=\"card-text\">const int LOADCELL_DOUT_PIN = 5;");
client.println("  <p class=\"card-text\">const int LOADCELL_SCK_PIN = 4;");


client.println("  <p class=\"card-text\">HX711 scale;");

client.println("  <p class=\"card-text\">void setup() {");
  
  client.println("  <p class=\"card-text\">Serial.begin(9600);  Mở cổng Serial ở 9600");
  client.println("  <p class=\"card-text\">lcd.init();  Khởi động LCD");
 client.println("  <p class=\"card-text\">lcd.backlight();  Bật đèn nền");
 client.println("  <p class=\"card-text\"> lcd.setCursor(1,0);  Cột 1, hàng 0");
 client.println("  <p class=\"card-text\"> lcd.print(\"DO KHOANG CACH\"); ");
  

  client.println("  <p class=\"card-text\">Serial.begin(9600);");
 client.println("  <p class=\"card-text\"> Serial.println(\"HX711 Demo\");");

 client.println("  <p class=\"card-text\"> Serial.println(\"Initializing the scale\");");

   client.println("  <p class=\"card-text\"> Initialize library with data output pin, clock input pin and gain factor.");
    client.println("  <p class=\"card-text\">Channel selection is made by passing the appropriate gain:");
   client.println("  <p class=\"card-text\"> - With a gain factor of 64 or 128, channel A is selected");
   client.println("  <p class=\"card-text\"> - With a gain factor of 32, channel B is selected");
   client.println("  <p class=\"card-text\"> By omitting the gain factor parameter, the library");
   client.println("  <p class=\"card-text\"> default \"128\" (Channel A) is used here.");
  client.println("  <p class=\"card-text\">scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);");

   client.println("  <p class=\"card-text\">Serial.println(\"Before setting up the scale:\");");
  client.println("  <p class=\"card-text\"> Serial.print(\"read: \t\t\");");
   client.println("  <p class=\"card-text\">Serial.println(scale.read());        print a raw reading from the ADC");

  client.println("  <p class=\"card-text\"> Serial.print(\"read average: \t\t\");");
   client.println("  <p class=\"card-text\">Serial.println(scale.read_average(20));     print the average of 20 readings from the ADC");

  client.println("  <p class=\"card-text\"> Serial.print(\"get value: \t\t\");");
  client.println("  <p class=\"card-text\"> Serial.println(scale.get_value(5));     print the average of 5 readings from the ADC minus the tare weight (not set yet)");

   client.println("  <p class=\"card-text\">Serial.print(\"get units: \t\t\");");
  client.println("  <p class=\"card-text\"> Serial.println(scale.get_units(5), 1);    print the average of 5 readings from the ADC minus tare weight (not set) divided");
       client.println("  <p class=\"card-text\">       by the SCALE parameter (not set yet)");

 client.println("  <p class=\"card-text\"> scale.set_scale(2280.f);                        this value is obtained by calibrating the scale with known weights; see the README for details");
  client.println("  <p class=\"card-text\">scale.tare();                 reset the scale to 0");

  client.println("  <p class=\"card-text\"> Serial.println(\"After setting up the scale:\");");

  client.println("  <p class=\"card-text\"> Serial.print(\"read: \t\t\");");
  client.println("  <p class=\"card-text\"> Serial.println(scale.read());                   print a raw reading from the ADC");

   client.println("  <p class=\"card-text\">Serial.print(\"read average: \t\t\");");
  client.println("  <p class=\"card-text\"> Serial.println(scale.read_average(20));         print the average of 20 readings from the ADC");

  client.println("  <p class=\"card-text\"> Serial.print(\"get value: \t\t\");");
  client.println("  <p class=\"card-text\"> Serial.println(scale.get_value(5));     print the average of 5 readings from the ADC minus the tare weight, set with tare()");

  client.println("  <p class=\"card-text\"> Serial.print(\"get units: \t\t\");");
   client.println("  <p class=\"card-text\">Serial.println(scale.get_units(5), 1);          print the average of 5 readings from the ADC minus tare weight, divided");
        client.println("  <p class=\"card-text\">      by the SCALE parameter set with set_scale");

  client.println("  <p class=\"card-text\"> Serial.println(\"Readings:\");");
client.println("  <p class=\"card-text\">}");


client.println("  <p class=\"card-text\">void loop() {");
 client.println("  <p class=\"card-text\"> Serial.print(\"one reading:\t\");");
 client.println("  <p class=\"card-text\"> Serial.print(scale.get_units(), 1);");
 client.println("  <p class=\"card-text\"> Serial.print(\"\t| average:\t\");");
  client.println("  <p class=\"card-text\">Serial.println( scale.get_units(5), 1  );");
  client.println("  <p class=\"card-text\">lcd.setCursor(0,1);");
 client.println("  <p class=\"card-text\"> lcd.print(\"A.X\\:\"); ");
 client.println("  <p class=\"card-text\"> lcd.setCursor(4,1);");
 client.println("  <p class=\"card-text\"> lcd.print(scale.get_units(5), 1);");

  client.println("  <p class=\"card-text\">scale.power_down();               put the ADC in sleep mode");
  client.println("  <p class=\"card-text\">delay(1000);");
 client.println("  <p class=\"card-text\"> scale.power_up();");
client.println("  <p class=\"card-text\">}");
   // client.println(" <div class=\"card-scroll\">");
    // client.println("  <p class=\"card-text\">Đây là một đoạn văn bản dài hơn, có thể cuộn lên và xuống</p>");
     //LOW = bật rơ lê đèn
     
    client.println(" </div>");
   client.println("</div>");
 client.println("</div>");
 client.println("</td>");


     client.println(" </table>");
     
     client.println("    </div>");
    client.println(" </div>");
    client.println("   </div>");
    client.println(" </div>");
          client.println("</td>");
    client.println(" </table>");
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
client.println("</td>");
  client.println(" </table>");
  
  client.print("<br>");
 client.println("<td>");
client.println("   <div class=\"card11\">");
  client.println(" </div>");
  client.println("</td>");
  client.print("<br>");
  
  client.println(" <table>");
  client.println(" <td>");
  client.println("   <div class=\"card6\">");
  //client.println("  <div class=\"card-header6\">This is a Header</div>");
  client.println("  <div class=\"card-body6\"> ");
  client.println(" <div class=\"card-image6\" style=\"display: flex; justify-content: center;\">");
  client.println(" <table>");
  client.println("<td>");
    client.println("   <div class=\"card7\">");
   // client.println("  <div class=\"card-header7\">This is a Header</div>");
    client.println("  <div class=\"card-body7\"> ");
    client.println(" <div class=\"card-image7\" style=\"display: flex; justify-content: center;\">");
        client.println("   <h6><img src=\"https://lh4.googleusercontent.com/WHzwnZl969ZxdfuvolEJoQ6Zkw4z079emo_3BhwotfmgChl_eDCrml67NvW8i09QMFgoB97MqdLzCGqCudo7URP4zQzayvHPy5fuBVle2rLnU9Bjxvbw1xvQseUWxyXFSQ=w1280\" width=\"270\" height=\"280\"> </h6> " );
    client.println("    </div>");
    client.println(" </div>");
    client.println("   </div>");
    client.println(" </div>");
          client.println("</td>");
  client.println(" </div>");
  client.println("</td>");
  client.println("<td>");
client.println("   <div class=\"card10\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");
       client.println("<td>");
    client.println("   <div class=\"card7\">");
   // client.println("  <div class=\"card-header7\">This is a Header</div>");
    client.println("  <div class=\"card-body7\"> ");
    client.println(" <div class=\"card-image7\" style=\"display: flex; justify-content: center;\">");
    client.println("   <h6><img src=\"https://scontent.fdad1-3.fna.fbcdn.net/v/t39.30808-6/441905112_1236253457351994_7934477371981764234_n.jpg?_nc_cat=110&ccb=1-7&_nc_sid=5f2048&_nc_ohc=HRGVSm4uA3UQ7kNvgF3QuZd&_nc_ht=scontent.fdad1-3.fna&oh=00_AYA9ztJIJrkvMQSxQWwd0griTu8n6bSu932ElK_8bimeDg&oe=6647C8CE\" width=\"270\" height=\"280\"> </h6> " );
    client.println("    </div>");
    client.println(" </div>");
    client.println("   </div>");
    client.println(" </div>");
          client.println("</td>");
          client.println("<td>");
client.println("   <div class=\"card9\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");
                 client.println("<td>");
                     client.println("   <div class=\"card8\">");
    //client.println("  <div class=\"card-header8\">This is a Header</div>");
    client.println("  <div class=\"card-body8\"> ");
    client.println(" <div class=\"card-image8\"style=\"display: flex; justify-content: center;\">");
    client.println(" <table>");
    client.println("<td>");

    client.println("  <h2 class=\"card-title\">THUYDIEN</h2>");
    client.println(" <div class=\"card\">");
   client.println("<div class=\"card-content\">");
   //client.println("  <h2 class=\"card-title\">Tiêu đề</h2>");

    client.println(" <div class=\"card-text\">");
    
  client.println("include\"LiquidCrystal_I2C.h>\"");
  client.println("include\"SoftwareSerial.h\"");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">SoftwareSerial bt(12,13);");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\"> LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">LiquidCrystal_I2C lcd1(0x26,16,2);");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">#define ANALOG_IN_PIN A1");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">#define ANALOG_IN_PIN A5");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">float adc_voltage = 0.0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">float in_voltage = 0.0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int bawn ;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">float R1 = 30000.0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">float R2 = 7500.0; ");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">float ref_voltage = 5.0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int adc_value = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int enco = 3;//toc do vong quay chan 3");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int dem = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int nhip =0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int rpm = 0; ");
  client.println("  <p class=\"card-text\">int timecho = 10000;// laays 1 vongf ddem laf 30 giay");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int L = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int Pr = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int V = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int I = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int U = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int Pn = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int H = 0;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">int led = 6;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">unsigned long thoigian;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">unsigned long hientai;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">void dem_xung()");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">{");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\"> dem++; //đếm xung");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">}");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">volatile int flow_frequency; // Đo xung cảm biến lưu lượng");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">unsigned int l_hour; // Tính toán số lít/giờ");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">unsigned char flowsensor = 2; // Cảm biến nối với chân 5");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">unsigned long currentTime;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">unsigned long cloopTime;");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">void flow () // Hàm ngắt");
  client.println("  <p class=\"card-text\">  <p class=\"card-text\">{");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\"> flow_frequency++;");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">}");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">#include <SFE_BMP180.h>");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">#include <Wire.h>");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">#include <I2Cdev.h>");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">SFE_BMP180 pressure;");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">#define ALTITUDE  0 ");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">void setup()");
    client.println("  <p class=\"card-text\">  <p class=\"card-text\">{");
      client.println("  <p class=\"card-text\">  <p class=\"card-text\">{");
        client.println("  <p class=\"card-text\">  <p class=\"card-text\">  pinMode(led, OUTPUT);  ");
        client.println("  <p class=\"card-text\">  <p class=\"card-text\"> }");
        client.println("  <p class=\"card-text\">  <p class=\"card-text\"> {");
          client.println("  <p class=\"card-text\">  <p class=\"card-text\">   Serial.begin(9600); ");
          client.println("  <p class=\"card-text\">  <p class=\"card-text\"> bt.begin(9600); ");
          client.println("  <p class=\"card-text\">  <p class=\"card-text\">bt.println(\"Ready\");");
          client.println("  <p class=\"card-text\">  <p class=\"card-text\">}");
          client.println("  <p class=\"card-text\">  <p class=\"card-text\">{");
            client.println("  <p class=\"card-text\">  <p class=\"card-text\">Serial.begin(9600);");
            client.println("  <p class=\"card-text\">  <p class=\"card-text\">}");
            client.println("  <p class=\"card-text\">  <p class=\"card-text\">{");
              client.println("  <p class=\"card-text\">Serial.begin(9600);");
              client.println("  <p class=\"card-text\">}");
              client.println("  <p class=\"card-text\">{");
                client.println("  <p class=\"card-text\"> Serial.begin(9600); //Mở cổng Serial ở 9600");
  client.println("  <p class=\"card-text\">lcd1.init(); //Khởi tạo màn hình LCD");
  client.println("  <p class=\"card-text\"> lcd1.backlight(); //Bật đèn màn hình lCD");
  client.println("  <p class=\"card-text\">}");
  client.println("  <p class=\"card-text\"> {");      
    client.println("  <p class=\"card-text\">Serial.begin(9600);");
    client.println("  <p class=\"card-text\">Serial.println(\"REBOOT\");");
    client.println("  <p class=\"card-text\"> if (pressure.begin())");
    client.println("  <p class=\"card-text\">Serial.println(\"BMP180 init success\");");
    client.println("  <p class=\"card-text\"> else");
    client.println("  <p class=\"card-text\">{");
      client.println("  <p class=\"card-text\">   Serial.println(\"BMP180 init fail\n\n\");");
      client.println("  <p class=\"card-text\">  while(1); ");
      client.println("  <p class=\"card-text\"> } ");
      client.println("  <p class=\"card-text\">}");
      client.println("  <p class=\"card-text\"> {");
        client.println("  <p class=\"card-text\"> Serial.begin(9600); ");
        client.println("  <p class=\"card-text\"> lcd.init(); ");
        client.println("  <p class=\"card-text\"> lcd.backlight(); ");
    //lcd.setCursor(1,0); ");
    client.println("  <p class=\"card-text\"> lcd1.init(); ");
    client.println("  <p class=\"card-text\"> lcd1.backlight(); ");
    //lcd1.setCursor(1,0); ");
    client.println("  <p class=\"card-text\">}");
    client.println("  <p class=\"card-text\">{");
      client.println("  <p class=\"card-text\">pinMode(flowsensor, INPUT);");
      client.println("  <p class=\"card-text\">digitalWrite(flowsensor, HIGH); ");
      client.println("  <p class=\"card-text\"> Serial.begin(9600);");
      client.println("  <p class=\"card-text\"> attachInterrupt(0, flow, RISING); ");
      client.println("  <p class=\"card-text\">sei(); ");
      client.println("  <p class=\"card-text\"> currentTime = millis();");
      client.println("  <p class=\"card-text\"> cloopTime = currentTime;");
      client.println("  <p class=\"card-text\">}");
      client.println("  <p class=\"card-text\">{");
        client.println("  <p class=\"card-text\"> Serial.begin(9600);");
        client.println("  <p class=\"card-text\"> pinMode(enco, INPUT);");
        client.println("  <p class=\"card-text\"> attachInterrupt(1, dem_xung, RISING);");
        client.println("  <p class=\"card-text\"> {");
          client.println("  <p class=\"card-text\">Serial.begin(9600); ");
          client.println("  <p class=\"card-text\">}");
          client.println("  <p class=\"card-text\">}");
          client.println("  <p class=\"card-text\">}");
          client.println("  <p class=\"card-text\">void loop()");
          client.println("  <p class=\"card-text\">{");
            client.println("  <p class=\"card-text\"> {");
              client.println("  <p class=\"card-text\"> char status;");
              client.println("  <p class=\"card-text\">double T,P,p0,a;");
              client.println("  <p class=\"card-text\">status = pressure.startTemperature();");
              client.println("  <p class=\"card-text\">delay(status);");
              client.println("  <p class=\"card-text\"> status = pressure.getTemperature(T);");
              client.println("  <p class=\"card-text\">  Serial.print(\"T= \");");
              client.println("  <p class=\"card-text\">  Serial.print(T,2);");
              client.println("  <p class=\"card-text\">  Serial.println(\" deg C, \");");
              client.println("  <p class=\"card-text\">  status = pressure.startPressure(3);");
              client.println("  <p class=\"card-text\">  delay(status);");
              client.println("  <p class=\"card-text\">  status = pressure.getPressure(P,T);     ");          
              client.println("  <p class=\"card-text\">   Serial.print(\" Pr= \");");
              client.println("  <p class=\"card-text\">  Serial.print(P/7-144.897,1);");
              client.println("  <p class=\"card-text\">  Serial.println(\" kPa, \");");
              client.println("  <p class=\"card-text\">    Serial.print(\"H= \");");
              client.println("  <p class=\"card-text\">  Serial.print((P/7-144.897)*0.101974,2 );");
              client.println("  <p class=\"card-text\">  Serial.println(\" mH2O, \");");
              client.println("  <p class=\"card-text\">  Pr=(P/7-144.897);");
              client.println("  <p class=\"card-text\"> H=((P/7-144.897)*0.101974 );");
              client.println("  <p class=\"card-text\"> p0 = pressure.sealevel(P,ALTITUDE); ");
              client.println("  <p class=\"card-text\"> a = pressure.altitude(P,p0);");
              client.println("  <p class=\"card-text\"> delay(5000);  ");
              client.println("  <p class=\"card-text\">}");
              client.println("  <p class=\"card-text\"> {");
                client.println("  <p class=\"card-text\"> currentTime = millis ();");
                client.println("  <p class=\"card-text\">if(currentTime >= (cloopTime + 10000))");
                client.println("  <p class=\"card-text\"> {");
                  client.println("  <p class=\"card-text\"> cloopTime = currentTime; ");
                  client.println("  <p class=\"card-text\">l_hour = (flow_frequency * 60 / 7.5/10); ");
                  client.println("  <p class=\"card-text\">flow_frequency = 0;   ");
                  client.println("  <p class=\"card-text\"> delay(100);");
        //if( L <0);
        //L = L  *(-1);
        client.println("  <p class=\"card-text\">  Serial.print((l_hour), DEC); ");
        client.println("  <p class=\"card-text\">Serial.println(\" L/hour\");");
        client.println("  <p class=\"card-text\">L = abs((l_hour));");
        client.println("  <p class=\"card-text\">}");
        client.println("  <p class=\"card-text\">}");
        client.println("  <p class=\"card-text\"> {");
          client.println("  <p class=\"card-text\"> thoigian = millis ();");    
          client.println("  <p class=\"card-text\">if (thoigian - hientai >= timecho)");
          client.println("  <p class=\"card-text\">{");
            client.println("  <p class=\"card-text\"> hientai = thoigian;");      
            client.println("  <p class=\"card-text\"> rpm = (dem/1)*60/100; ");
          client.println("  <p class=\"card-text\"> Serial.print(\"\t\t\t\t\"); Serial.print(\"So xung/s: \"); Serial.println(dem);");
          client.println("  <p class=\"card-text\"> Serial.print(\"\t\t\t\t\"); Serial.print(\"RPM: \"); Serial.println(rpm);");
          client.println("  <p class=\"card-text\">delay(100); ");
          client.println("  <p class=\"card-text\">dem = 0;");
          client.println("  <p class=\"card-text\"> V =  abs((rpm)); ");
          client.println("  <p class=\"card-text\"> hientai = thoigian;  ");
          client.println("  <p class=\"card-text\">}");
          client.println("  <p class=\"card-text\"> }");
          client.println("  <p class=\"card-text\">{");
      client.println("  <p class=\"card-text\">float average = 0;");
      client.println("  <p class=\"card-text\">for(int i = 0; i < 1000; i++) {");
        //average = average + (.0264 * analogRead(A0) -13.51);//for the 5A mode,  
  //   average = average + (.049 * analogRead(A0) -25);// for 20A mode
  // average = average + (.742 * analogRead(A0) -37.8);// for 30A mode
  client.println("  <p class=\"card-text\">  bawn = average =  average + (.0264 * analogRead(A5) -9.459);");
  client.println("  <p class=\"card-text\">delay(1);");
  client.println("  <p class=\"card-text\">}");
      //I=(average); 
    // if( (average) <0);
  //average = average  *(-1); 
  //I=abs((average)); 
  client.println("  <p class=\"card-text\"> if( (U) <20){");
    client.println("  <p class=\"card-text\">(average)=0; ");
    client.println("  <p class=\"card-text\">I = 0 ;} ");
    client.println("  <p class=\"card-text\">else {I = abs((average));}");
    client.println("  <p class=\"card-text\">Serial.print(\"APE :\");");
    client.println("  <p class=\"card-text\">Serial.println(average/1000);");
    client.println("  <p class=\"card-text\">lcd1.setCursor(0,0);");
    client.println("  <p class=\"card-text\">lcd1.print(\"I= \");");
    client.println("  <p class=\"card-text\">  lcd1.setCursor(4,0);");
    client.println("  <p class=\"card-text\"> lcd1.print(abs(average )/1000 );");  
    client.println("  <p class=\"card-text\"> lcd1.print(\" A\");");
    client.println("  <p class=\"card-text\">}");
    client.println("  <p class=\"card-text\">{");
      client.println("  <p class=\"card-text\">adc_value = analogRead(A1);  ");
      client.println("  <p class=\"card-text\">adc_voltage  = (adc_value * ref_voltage) / 1024.0;");
      client.println("  <p class=\"card-text\"> in_voltage = adc_voltage*(R1+R2)/R2;");
      client.println("  <p class=\"card-text\"> U=((in_voltage)*1000);//mV");
      client.println("  <p class=\"card-text\">Serial.print(\"Voltage = \");");
      client.println("  <p class=\"card-text\">Serial.println(in_voltage, 2);");
      client.println("  <p class=\"card-text\"> lcd1.setCursor(0,1);");
      client.println("  <p class=\"card-text\"> lcd1.print(\"U= \");");
      client.println("  <p class=\"card-text\"> lcd1.setCursor(4,1);");
      client.println("  <p class=\"card-text\"> lcd1.print(in_voltage, 2);");
      client.println("  <p class=\"card-text\"> lcd1.print(\" V\");");
        client.println("  <p class=\"card-text\"> delay(500);");
      client.println("  <p class=\"card-text\">}");
  client.println("  <p class=\"card-text\">digitalWrite(led, HIGH);   ");
  client.println("  <p class=\"card-text\"> delay(1500);           ");    
    client.println("  <p class=\"card-text\">lcd.setCursor(0,0);");
  client.println("  <p class=\"card-text\">lcd.print("                ");");
  client.println("  <p class=\"card-text\">lcd.setCursor(0,1);");
  client.println("  <p class=\"card-text\">lcd.print("                ");");
  client.println("  <p class=\"card-text\">lcd.setCursor(1,1);");
  client.println("  <p class=\"card-text\"> lcd.print(\"Pr= \");");
    client.println("  <p class=\"card-text\">lcd.print(Pr);    ");
    client.println("  <p class=\"card-text\">lcd.print(\" kPa\");");
    client.println("  <p class=\"card-text\"> lcd.setCursor(1,0);");
    client.println("  <p class=\"card-text\"> lcd.print(\"H= \");");
    client.println("  <p class=\"card-text\"> lcd.setCursor(6,0);");
    client.println("  <p class=\"card-text\"> lcd.print(H);    ");
    client.println("  <p class=\"card-text\"> lcd.print(\" m\");");
    client.println("  <p class=\"card-text\"> delay(5000);");
    client.println("  <p class=\"card-text\">lcd.setCursor(0,0);");
  client.println("  <p class=\"card-text\">lcd.print("                ");");
  client.println("  <p class=\"card-text\">lcd.setCursor(0,1);");
  client.println("  <p class=\"card-text\">lcd.print("                ");");
  client.println("  <p class=\"card-text\"> lcd.setCursor(1,0);");
    client.println("  <p class=\"card-text\"> lcd.print(\"V= \");");
    client.println("  <p class=\"card-text\"> lcd.print(V);");
    client.println("  <p class=\"card-text\">lcd.print(\" v/p\");");
    client.println("  <p class=\"card-text\">lcd.setCursor(1,1);");
  client.println("  <p class=\"card-text\"> lcd.print(\"L= \");");
  client.println("  <p class=\"card-text\"> lcd.print(L);");
    client.println("  <p class=\"card-text\"> lcd.print(\" l/h\");");
    client.println("  <p class=\"card-text\">bt.print(L);//1  lưu lượng send distance to MIT App");
  client.println("  <p class=\"card-text\"> bt.print(\";\");");
  client.println("  <p class=\"card-text\"> bt.print(Pr); //2  áp xuất send distance to MIT App ");
    client.println("  <p class=\"card-text\">bt.print(\";\");");
  client.println("  <p class=\"card-text\">bt.print(V);//3  toc do send distance to MIT App");
  client.println("  <p class=\"card-text\">bt.print(\";\");");
  client.println("  <p class=\"card-text\"> bt.print(U);//4  dien thetuabin send distance to MIT App ");
  client.println("  <p class=\"card-text\">bt.print(\";\");");
  client.println("  <p class=\"card-text\">bt.print(I);//5  dong dien tuabin send distance to MIT App ");
  client.println("  <p class=\"card-text\">bt.print(\";\");");
  client.println("  <p class=\"card-text\">bt.print(H);//6 do cao tuabin send distance to MIT App ");
  client.println("  <p class=\"card-text\">bt.print(\";\");");
  //bt.print(in_voltage, 2);//hiệu dien the tuabin send distance to MIT App 
  //bt.print(";");


  client.println("  <p class=\"card-text\">}");
    

  
    client.println(" </div>");
   client.println("</div>");
 client.println("</div>");
 client.println("</td>");


client.println("<td>");
client.println("   <div class=\"card9\">");
  client.println(" </div>");
  client.println("</td>");

 client.println("<td>");
 client.println("  <h2 class=\"card-title\">XANUOC</h2>");
    client.println(" <div class=\"card\">");
   client.println("<div class=\"card-content\">");
   //client.println("  <h2 class=\"card-title\">Tiêu đề</h2>");
//client.println("  <p class=\"card-text\">Đây là một đoạn văn bản</p>");
   // client.println(" <div class=\"card-scroll\">");
    // client.println("  <p class=\"card-text\">Đây là một đoạn văn bản dài hơn, có thể cuộn lên và xuống</p>");
     //LOW = bật rơ lê đèn
client.println("  <p class=\"card-text\"> #include <Wire.h>");
client.println("  <p class=\"card-text\"> #include <LiquidCrystal_I2C.h>");
client.println("  <p class=\"card-text\"> LiquidCrystal_I2C lcd(0x27, 20, 4);");
client.println("  <p class=\"card-text\"> #define RO1  4");
client.println("  <p class=\"card-text\"> #define RO2  5");
client.println("  <p class=\"card-text\"> #define RO3  6");
client.println("  <p class=\"card-text\"> #define RO4  7");
client.println("  <p class=\"card-text\"> int R1;");
client.println("  <p class=\"card-text\"> int R2;");
client.println("  <p class=\"card-text\"> int R3;");
client.println("  <p class=\"card-text\"> int R4;");
client.println("  <p class=\"card-text\"> int L ;");
client.println("  <p class=\"card-text\"> int i = 1 ;");
client.println("  <p class=\"card-text\"> //char array1[] = \"      INOVATRIX\";  ");
client.println("  <p class=\"card-text\"> //char array2[] = \"        LIKE\";     ");
client.println("  <p class=\"card-text\"> //char array3[] = \"     SUBSCRIBE\";   ");
client.println("  <p class=\"card-text\"> //char array4[] = \"       SHARE\";");

client.println("  <p class=\"card-text\"> volatile int flow_frequency; ");
client.println("  <p class=\"card-text\"> unsigned int l_hour; ");
client.println("  <p class=\"card-text\"> unsigned char flowsensor = 2; ");
client.println("  <p class=\"card-text\"> unsigned long currentTime;");
client.println("  <p class=\"card-text\"> unsigned long cloopTime;");
client.println("  <p class=\"card-text\"> void flow () // Hàm ngắt");
client.println("  <p class=\"card-text\"> {");
  client.println("  <p class=\"card-text\">  flow_frequency++;");
  client.println("  <p class=\"card-text\"> }     ");
  client.println("  <p class=\"card-text\"> void setup() {   ");
    client.println("  <p class=\"card-text\">  {             ");
    client.println("  <p class=\"card-text\">   pinMode(RO1, OUTPUT);  ");  
    client.println("  <p class=\"card-text\">  pinMode(RO2, OUTPUT);  ");
    client.println("  <p class=\"card-text\">  pinMode(RO3, OUTPUT);  ");
    client.println("  <p class=\"card-text\">  pinMode(RO4, OUTPUT);  ");
    client.println("  <p class=\"card-text\">  }");
    client.println("  <p class=\"card-text\">  {");
      client.println("  <p class=\"card-text\"> {");
        client.println("  <p class=\"card-text\">  Serial.begin(9600); //Mở cổng Serial ở 9600");
        client.println("  <p class=\"card-text\"> lcd.init(); //Khởi động LCD");
        client.println("  <p class=\"card-text\">  lcd.backlight(); //Bật đèn nền");
        client.println("  <p class=\"card-text\">  //lcd.setCursor(1,0); //Cột 1, hàng 0");
        client.println("  <p class=\"card-text\">  }");
        client.println("  <p class=\"card-text\">  {");
          client.println("  <p class=\"card-text\">   pinMode(flowsensor, INPUT);");
          client.println("  <p class=\"card-text\">  digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up");
          client.println("  <p class=\"card-text\">  Serial.begin(9600);");
          client.println("  <p class=\"card-text\">  attachInterrupt(0, flow, RISING); // Setup Interrupt");
          client.println("  <p class=\"card-text\">  sei(); // Enable interrupts");
          client.println("  <p class=\"card-text\">  currentTime = millis();");
          client.println("  <p class=\"card-text\">  cloopTime = currentTime;");
          client.println("  <p class=\"card-text\"> }");
          client.println("  <p class=\"card-text\"> }");
          client.println("  <p class=\"card-text\"> }");
        
          client.println("  <p class=\"card-text\"> // Hàm loop chạy mãi mãi sau khi kết thúc hàm setup()");
          client.println("  <p class=\"card-text\"> void loop() {");
            client.println("  <p class=\"card-text\">  {");
              client.println("  <p class=\"card-text\">  currentTime = millis();");
              client.println("  <p class=\"card-text\">  // Every second, calculate and print litres/hour");
              client.println("  <p class=\"card-text\">  if(currentTime >= (cloopTime + 15000))");
              client.println("  <p class=\"card-text\"> {");
                client.println("  <p class=\"card-text\">   cloopTime = currentTime; // Updates cloopTime");
        client.println("  <p class=\"card-text\">   // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.");
        client.println("  <p class=\"card-text\">  l_hour = (flow_frequency * 60 / 7.5/15); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour");
        client.println("  <p class=\"card-text\">  flow_frequency = 0; // Reset Counter");
        client.println("  <p class=\"card-text\">  L = l_hour;");
        client.println("  <p class=\"card-text\">  Serial.print(l_hour, DEC); // Print litres/hour");
        client.println("  <p class=\"card-text\">   Serial.println(\" L/hour\");");
//if ( L <= 0 );
 ////{
 // L = L * -1;
 //}
 client.println("  <p class=\"card-text\"> Serial.println(L); // Print litres/hour");
       // lcd.setCursor(1,0);
      // lcd.print("LUU LUONG :");
      //lcd.setCursor(11,1);
     // lcd.print(l_hour);
     client.println("  <p class=\"card-text\">  }   ");
     client.println("  <p class=\"card-text\"> }");
     client.println("  <p class=\"card-text\"> {");
      client.println("  <p class=\"card-text\">  if ( L<100)");
      client.println("  <p class=\"card-text\"> { ");
        client.println("  <p class=\"card-text\">  digitalWrite(RO3, LOW);");
        client.println("  <p class=\"card-text\">  digitalWrite(RO1, HIGH);");
        client.println("  <p class=\"card-text\"> digitalWrite(RO2, HIGH);");
        client.println("  <p class=\"card-text\"> digitalWrite(RO4, LOW);");
   
        client.println("  <p class=\"card-text\">  lcd.setCursor(0,0);");
        client.println("  <p class=\"card-text\">  lcd.print(\"CONG1:\") ;");
        client.println("  <p class=\"card-text\"> lcd.setCursor(7,0);");
        client.println("  <p class=\"card-text\">  lcd.print(\"OFF\") ; ");
        client.println("  <p class=\"card-text\">  lcd.setCursor(0,1);");
        client.println("  <p class=\"card-text\">  lcd.print(\"CONG2:\") ;");
        client.println("  <p class=\"card-text\">  lcd.setCursor(7,1);");
        client.println("  <p class=\"card-text\">  lcd.print(\"OFF\");");
        client.println("  <p class=\"card-text\">  lcd.setCursor(0,2);");
   client.println("  <p class=\"card-text\">  lcd.print(\"DEN BAO1:\"); ");
   client.println("  <p class=\"card-text\">  lcd.setCursor(10,2);");
   client.println("  <p class=\"card-text\"> lcd.print(\"OFF\")  ;");
   client.println("  <p class=\"card-text\">    lcd.setCursor(0,3);");
   client.println("  <p class=\"card-text\"> lcd.print(\"DEN BAO2:\");");
   client.println("  <p class=\"card-text\"> lcd.setCursor(10,3);");
   client.println("  <p class=\"card-text\"> lcd.print(\"OFF\");");
   client.println("  <p class=\"card-text\">  }");
   client.println("  <p class=\"card-text\"> else if ( L<200 && L>100)");
   client.println("  <p class=\"card-text\">  {");
    
    client.println("  <p class=\"card-text\">  digitalWrite(RO3, LOW);");
  client.println("  <p class=\"card-text\">  digitalWrite(RO1, LOW);");
  client.println("  <p class=\"card-text\">  digitalWrite(RO2, HIGH);");
  client.println("  <p class=\"card-text\"> digitalWrite(RO4, HIGH);");
   
  client.println("  <p class=\"card-text\"> lcd.setCursor(0,0);");
   client.println("  <p class=\"card-text\">   lcd.print(\"CONG1:\") ;");
   client.println("  <p class=\"card-text\"> lcd.setCursor(7,0);");
   client.println("  <p class=\"card-text\">  lcd.print(\"ONN\") ; ");
   client.println("  <p class=\"card-text\"> lcd.setCursor(0,1);");
   client.println("  <p class=\"card-text\"> lcd.print(\"CONG2:\") ;");
   client.println("  <p class=\"card-text\"> lcd.setCursor(7,1);");
   client.println("  <p class=\"card-text\">  lcd.print(\"OFF\");");
   client.println("  <p class=\"card-text\">  lcd.setCursor(0,2);");
   client.println("  <p class=\"card-text\"> lcd.print(\"DEN BAO1:\"); ");
   client.println("  <p class=\"card-text\"> lcd.setCursor(10,2);");
   client.println("  <p class=\"card-text\">  lcd.print(\"ONN\")  ;");
   client.println("  <p class=\"card-text\">  lcd.setCursor(0,3);");
   client.println("  <p class=\"card-text\">  lcd.print(\"DEN BAO2:\");");
   client.println("  <p class=\"card-text\">  lcd.setCursor(10,3);");
   client.println("  <p class=\"card-text\">  lcd.print(\"OFF\");");


   client.println("  <p class=\"card-text\">  }");
  
  
   client.println("  <p class=\"card-text\">  else if ( L>200)");
   client.println("  <p class=\"card-text\"> {");
    client.println("  <p class=\"card-text\"> digitalWrite(RO3, LOW);");
    client.println("  <p class=\"card-text\">  digitalWrite(RO1, LOW);");
    client.println("  <p class=\"card-text\">  digitalWrite(RO2, LOW);");
    client.println("  <p class=\"card-text\">  digitalWrite(RO4, LOW);");
   
    client.println("  <p class=\"card-text\">  lcd.setCursor(0,0);");
    client.println("  <p class=\"card-text\">  lcd.print(\"CONG1:\") ;");
    client.println("  <p class=\"card-text\">  lcd.setCursor(7,0);");
    client.println("  <p class=\"card-text\"> lcd.print(\"ONN\") ; ");
    client.println("  <p class=\"card-text\">  lcd.setCursor(0,1);");
    client.println("  <p class=\"card-text\"> lcd.print(\"CONG2:\") ;");
    client.println("  <p class=\"card-text\">  lcd.setCursor(7,1);");
    client.println("  <p class=\"card-text\">  lcd.print(\"ONN\");");
    client.println("  <p class=\"card-text\">  lcd.setCursor(0,2);");
    client.println("  <p class=\"card-text\">  lcd.print(\"DEN BAO1:\"); ");
    client.println("  <p class=\"card-text\">  lcd.setCursor(10,2);");
    client.println("  <p class=\"card-text\">  lcd.print(\"ONN\")  ;");
    client.println("  <p class=\"card-text\">  lcd.setCursor(0,3);");
    client.println("  <p class=\"card-text\">  lcd.print(\"DEN BAO2:\");");
    client.println("  <p class=\"card-text\">   lcd.setCursor(10,3);");
    client.println("  <p class=\"card-text\">  lcd.print(\"ONN\");");
    client.println("  <p class=\"card-text\">  }");
    client.println("  <p class=\"card-text\">  }");
    client.println("  <p class=\"card-text\">  delay ( 5000);");
    client.println("  <p class=\"card-text\"> }");
    client.println(" </div>");
   client.println("</div>");
 client.println("</div>");
 client.println("</td>");

     client.println(" </table>");
     
     client.println("    </div>");
    client.println(" </div>");
    client.println("   </div>");
    client.println(" </div>");
          client.println("</td>");
          
  
    client.println(" </table>");
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  
client.println("</td>");

  
  client.println(" </table>");


  
  client.println(" <table>");
    client.println("   <tr>");
  client.println("<td>");
client.println("   <div class=\"card19\">");
  client.println(" </div>");
  client.println("</td>");
    client.println("   </tr>");
  client.println("   <tr>");
 client.println(" <td>");

  
  client.println("   <div class=\"card1\">");
  client.println("  <div class=\"card-header\">FACEBOOK</div>");
  client.println("  <div class=\"card-body\"> ");
  client.println(" <div class=\"card-image\" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://lh3.googleusercontent.com/dSPh9CG2JuOJKHQhoAKa2cqJ16Rn2C6JxHS2I0R5Ghnbh3MG4U3OZhNTB5g70nBHTOp2ByA8trNQAeajlttt0FE=w1280\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
client.println("</td>");

client.println("<td>");
client.println("   <div class=\"card19\">");
  client.println(" </div>");
  client.println("</td>");
  
client.println("<td>");
    client.println("   <div class=\"card2\">");
  client.println("  <div class=\"card-header2\">    ZALO</div>");
  client.println("  <div class=\"card-body2\"> ");
  client.println(" <div class=\"card-image2 \" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://lh4.googleusercontent.com/o3QSUVnhJyRZLNogFePJpK3QNGntgyp4FSVycPNY2ufeJDWMnLWZ_8uRELCQyNJql0kN91xulI6_R7I7WIVpnJzA8YL_0-GpYA8O3ftOJuvbq9rU8hmVIO0weOA0g049LQ=w1280\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  client.println("</td>");
  
  
client.println("<td>");
client.println("   <div class=\"card19\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");

    client.println("   <div class=\"card4\">");
  client.println("  <div class=\"card-header4\">TELEHRAM</div>");
  client.println("  <div class=\"card-body4\"> ");
  client.println(" <div class=\"card-image4 \" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://lh3.googleusercontent.com/HtkMxUn5iJ_vZeTKsvTP5ms9yb6ncrUxE_KPB1pZ6KyFGW3IHfoVqtW-yQntTAahstGs6oNg6-6qpC3PfzJmaF3FP2mEpBYBsmBlmEBP2UVkc0tIm8a4Wu7d34cTnwigyA=w1280\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  client.println("</td>");

  client.println("<td>");
client.println("   <div class=\"card19\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");

    client.println("   <div class=\"card12\">");
  client.println("  <div class=\"card-header12\">TWITER</div>");
  client.println("  <div class=\"card-body12\"> ");
  client.println(" <div class=\"card-image12 \" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://scontent.fdad1-1.fna.fbcdn.net/v/t39.30808-6/441526041_1235013517475988_3009343251269314617_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=5f2048&_nc_ohc=QlVHE0T7ongQ7kNvgFUPSLY&_nc_ht=scontent.fdad1-1.fna&oh=00_AYC8Yog3r83wgWRcy6LQySzGRh7AIx2UxHlflae1SV9gIw&oe=6644F660\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  client.println("</td>");

  client.println("<td>");
client.println("   <div class=\"card19\">");
  client.println(" </div>");
  client.println("</td>");
client.println("<td>");

    client.println("   <div class=\"card5\">");
  client.println("  <div class=\"card-header5\">GITHUP</div>");
  client.println("  <div class=\"card-body5\"> ");
  client.println(" <div class=\"card-image5 \" style=\"display: flex; justify-content: center;\">");
  client.println("   <h6><img src=\"https://lh4.googleusercontent.com/ZQGxshucDlkGxQv3qbMFm8Yn2ogpGrfCr9Hbnx-V7NqeMtwzoZ4VVqNht8zfvKkkgjGXqUo6ZxvqGsg_EblyW1M=w1280\" width=\"250\" height=\"250\"> </h6> " );
  client.println("    </div>");
  client.println(" </div>");
  client.println("   </div>");
  client.println(" </div>");
  client.println("</td>");
  
  client.println("<a href=\"/LEDON\"\"><button class=\"button\">ON</button></a>");
  client.println("<a href=\"/https://www.facebook.com/profile.php?id=100088447571224\"\"><button class=\"button\">OFF</button></a>");
  //client.println("   <h7><img src=\"https://scontent.fdad1-4.fna.fbcdn.net/v/t39.30808-6/439936086_1232125754431431_540399052568426477_n.jpg?stp=dst-jpg_p526x296&_nc_cat=105&ccb=1-7&_nc_sid=5f2048&_nc_ohc=9jB8sU2mC18Q7kNvgH_Exqk&_nc_ht=scontent.fdad1-4.fna&oh=00_AfBidlsK2GfB5CuOOj66KmOIun55LT0rGsQWwLy1TA4Efw&oe=663EA6A6\" width=\"250\" height=\"250\"> </h7> " );
  client.println(" </table>");
  client.print("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
