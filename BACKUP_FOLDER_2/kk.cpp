
#include<bits/stdc++.h>
#define DATA_OFFSET_OFFSET 0x000A
#define WIDTH_OFFSET 0x0012
#define HEIGHT_OFFSET 0x0016
#define BITS_PER_PIXEL_OFFSET 0x001C
#define HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define NO_COMPRESION 0
#define MAX_NUMBER_OF_COLORS 0
#define ALL_COLORS_REQUIRED 0
 
using namespace std;

typedef unsigned int int32;
typedef short int16;
typedef unsigned char byte;
 
void ReadImage(const char *fileName,byte **pixels, int32 *width, int32 *height, int32 *bytesPerPixel)
{
        FILE *imageFile = fopen(fileName, "rb");
        int32 dataOffset;
        fseek(imageFile, DATA_OFFSET_OFFSET, SEEK_SET);
        fread(&amp;dataOffset, 4, 1, imageFile);
        fseek(imageFile, WIDTH_OFFSET, SEEK_SET);
        fread(width, 4, 1, imageFile);
        fseek(imageFile, HEIGHT_OFFSET, SEEK_SET);
        fread(height, 4, 1, imageFile);
        int16 bitsPerPixel;
        fseek(imageFile, BITS_PER_PIXEL_OFFSET, SEEK_SET);
        fread(&amp;bitsPerPixel, 2, 1, imageFile);
        *bytesPerPixel = ((int32)bitsPerPixel) / 8;
 
        int paddedRowSize = (int)(4 * ceil((float)(*width) / 4.0f))*(*bytesPerPixel);
        int unpaddedRowSize = (*width)*(*bytesPerPixel);
        int totalSize = unpaddedRowSize*(*height);
        *pixels = (byte*)malloc(totalSize);
        int i = 0;
        byte *currentRowPointer = *pixels+((*height-1)*unpaddedRowSize);
        for (i = 0; i &lt; *height; i++)
        {
                fseek(imageFile, dataOffset+(i*paddedRowSize), SEEK_SET);
            fread(currentRowPointer, 1, unpaddedRowSize, imageFile);
            currentRowPointer -= unpaddedRowSize;
        }
 
        fclose(imageFile);
}
 
void WriteImage(const char *fileName, byte *pixels, int32 width, int32 height,int32 bytesPerPixel)
{
        FILE *outputFile = fopen(fileName, "wb");
        //*****HEADER************//
        const char *BM = "BM";
        fwrite(&amp;BM[0], 1, 1, outputFile);
        fwrite(&amp;BM[1], 1, 1, outputFile);
        int paddedRowSize = (int)(4 * ceil((float)width/4.0f))*bytesPerPixel;
        int32 fileSize = paddedRowSize*height + HEADER_SIZE + INFO_HEADER_SIZE;
        fwrite(&amp;fileSize, 4, 1, outputFile);
        int32 reserved = 0x0000;
        fwrite(&amp;reserved, 4, 1, outputFile);
        int32 dataOffset = HEADER_SIZE+INFO_HEADER_SIZE;
        fwrite(&amp;dataOffset, 4, 1, outputFile);
 
        //*******INFO*HEADER******//
        int32 infoHeaderSize = INFO_HEADER_SIZE;
        fwrite(&amp;infoHeaderSize, 4, 1, outputFile);
        fwrite(&amp;width, 4, 1, outputFile);
        fwrite(&amp;height, 4, 1, outputFile);
        int16 planes = 1; //always 1
        fwrite(&amp;planes, 2, 1, outputFile);
        int16 bitsPerPixel = bytesPerPixel * 8;
        fwrite(&amp;bitsPerPixel, 2, 1, outputFile);
        //write compression
        int32 compression = NO_COMPRESION;
        fwrite(&amp;compression, 4, 1, outputFile);
        write image size (in bytes)
        int32 imageSize = width*height*bytesPerPixel;
        fwrite(&amp;imageSize, 4, 1, outputFile);
        int32 resolutionX = 11811; //300 dpi
        int32 resolutionY = 11811; //300 dpi
        fwrite(&amp;resolutionX, 4, 1, outputFile);
        fwrite(&amp;resolutionY, 4, 1, outputFile);
        int32 colorsUsed = MAX_NUMBER_OF_COLORS;
        fwrite(&amp;colorsUsed, 4, 1, outputFile);
        int32 importantColors = ALL_COLORS_REQUIRED;
        fwrite(&amp;importantColors, 4, 1, outputFile);
        int i = 0;
        int unpaddedRowSize = width*bytesPerPixel;
        for ( i = 0; i &lt; height; i++)
        {
                int pixelOffset = ((height - i) - 1)*unpaddedRowSize;
                fwrite(&amp;pixels[pixelOffset], 1, paddedRowSize, outputFile);
        }
        fclose(outputFile);
}
 
int main()
{
        byte *pixels;
        int32 width;
        int32 height;
        int32 bytesPerPixel;
        ReadImage("img.bmp", &amp;pixels, &amp;width, &amp;height,&amp;bytesPerPixel);
        WriteImage("img2.bmp", pixels, width, height, bytesPerPixel);
        free(pixels);
        return 0;
}