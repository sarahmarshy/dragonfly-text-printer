#include "mbed.h"
#include "MTSASInterface.h"
#include "AS289R2.h"

MTSASInterface cell(RADIO_TX, RADIO_RX);
AS289R2 tp(D1);
Serial pc(USBTX, USBRX);

void print_sms(char* msg){
    printf("msg: %s\r\n", msg);
    tp.printf("%s\r\r", msg);
}

int main() {
    // Brings up the dragonfly
    printf("cell texting example\r\n");
    // An APN is required for GSM radios.
    static const char apn[] = "wap.cingular";
    printf("connecting to network...\r\n");
    cell.connect(apn);
    printf("connected!\r\n");
    
    //Initialize printer
    tp.initialize();
    tp.putLineFeed(2); 
    tp.setANKFont(AS289R2::ANK_16x16);
    
    //Handle incoming messages with print_sms
    cell.sms_attach(&print_sms);
    printf("listening for texts\r\n");
    
    while(true){}
    
    cell.disconnect();
    printf("Done\n");
}

