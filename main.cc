#include <drogon/drogon.h>
#include <iostream>

int main() {
    //Set HTTP listener address and port
    std::cout << "Listrning on 0.0.0.0:8848" << std::endl;
    drogon::app().addListener("0.0.0.0",8848);
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
