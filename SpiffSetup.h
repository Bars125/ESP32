#ifndef SPIFF_Setup_H
#define SPIFF_Setup_H

#include <SPIFFS.h>

void SPIFFSInit();
void wavHeader(byte* header, int wavSize);
void listSPIFFS();

File file;
const char filename[] = "/recording.wav";
const int headerSize = 44;

#endif