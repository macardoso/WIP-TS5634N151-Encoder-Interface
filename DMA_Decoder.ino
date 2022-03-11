#include "Arduino.h"
#include "decoder.h"
#include "QuadEncoder.h"

Manchester::Decoder decoder;
Manchester::TS5643Field result;
QuadEncoder myEnc1(1, 1, 0, 0);
uint32_t encCnt = 0;
bool preloadStatus = 1;
bool firstScan = 1;

void setup()
{
    myEnc1.setInitConfig();  //
    myEnc1.init();
    decoder.begin(2E6); // 500ns clock
}

void loop()
{
    while (!decoder.resultBuffer.isEmpty())
    {
        decoder.resultBuffer.pop(result);
        if (firstScan){
           myEnc1.setInitConfig();  //
           myEnc1.EncConfig.positionInitialValue = (result.count)*4;
           myEnc1.init();
           firstScan = 0;
        }
        if (preloadStatus == 1 && result.PS == 0){
           myEnc1.setInitConfig();  //
           myEnc1.EncConfig.positionInitialValue = (result.count)*4;
           myEnc1.init();
           preloadStatus = 0;
        }
        encCnt = myEnc1.read();
        Serial.print("Quad Enc Cnt: ");
        Serial.print(encCnt);
        Serial.print(", Serial Enc Cnt: ");
        Serial.println((result.count)*4);
        //Serial.println(result);
    }
    delay(1); // do something else, make sure you don't spend too much time otherwise the edge buffer might overflow and you'll loose data
}

void yield()
{
    decoder.tick(); // tick the decoder from yield to get ticks even during delays and other time consuming tasks...
}
