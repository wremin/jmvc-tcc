#include <stdlib.h>

#include "MemTracingFile.h"

MemTracingFile::MemTracingFile() {
}

MemTracingFile::~MemTracingFile() {
}

int MemTracingFile::refMinX;
int MemTracingFile::refMinY;
int MemTracingFile::refMaxX;
int MemTracingFile::refMaxY;
unsigned int MemTracingFile::refFrame;
unsigned int MemTracingFile::refView;
unsigned int MemTracingFile::currMbX;
unsigned int MemTracingFile::currMbY;
unsigned int MemTracingFile::currFrame;
unsigned int MemTracingFile::currView;
unsigned int MemTracingFile::blkSize;
unsigned int MemTracingFile::targetBlk;
FILE* MemTracingFile::traceFile;
FILE* MemTracingFile::otherFile;
FILE* MemTracingFile::startPointsFile;
unsigned char MemTracingFile::biPrediction;
unsigned char MemTracingFile::refinement;


void MemTracingFile::setTraceFile(FILE* newFile) {
	traceFile = newFile;
}

void MemTracingFile::initTraceFile(std::string nome) {
	traceFile = fopen(nome.c_str(),"w");
}

void MemTracingFile::closeTraceFile() {
	fclose(traceFile);
}

void MemTracingFile::initOtherFile(std::string nome) {
	otherFile = fopen(nome.c_str(),"w");
}

void MemTracingFile::initStartPointsFile(std::string nome) {
    startPointsFile = fopen(nome.c_str(),"w");
}

void MemTracingFile::closeStartPointsFile() {
    fclose(startPointsFile);
}

void MemTracingFile::closeOtherFile() {
	fclose(otherFile);
}

int MemTracingFile::printOtherFile(char* s, ...) {
	va_list args;
	va_start(args, s);
	return fprintf(otherFile,s,args);
}

void MemTracingFile::setMinRefArea(int x, int y) {
	//VERIFICAR SE AJUSTE ESTÁ CORRETO!!!!!
	refMinX = x + currMbX*16;
	refMinY = y + currMbY*16;
}

void MemTracingFile::setMaxRefArea(int x, int y) {
	refMaxX = x + currMbX*16;
	refMaxY = y + currMbY*16;
}

void MemTracingFile::setRefFrame(unsigned int frame) {
	refFrame = frame;
}
void MemTracingFile::setRefView(unsigned int view) {
	refView = view;
}
void MemTracingFile::setCurrMb(unsigned int x, unsigned int y) {
	currMbX = x;
	currMbY = y;
}
void MemTracingFile::setCurrFrame(unsigned int frame) {
	currFrame = frame;
}
void MemTracingFile::setCurrView(unsigned int view) {
	currView = view;
}
void MemTracingFile::setBlkSize(unsigned int size) {
	blkSize = size;
}
void MemTracingFile::setTargetBlk(unsigned int blk) {
	targetBlk = blk;
}
void MemTracingFile::setRefRectangle(int x, int y) {
	if(blkSize == 1) { //MB_16x16
		setMinRefArea(x,y);
		setMaxRefArea(x+16,y+16);
	}
}

void MemTracingFile::setBiPrediction(char c) {
	biPrediction = c;
}

std::string MemTracingFile::toString() {
	char traceObj[50];
	sprintf(traceObj,"%d %d\n%d %d\n%u %u\n%d %d\n%u %u\n%u\n\n",
			refMinX, refMinY,
			refMaxX, refMaxY,
			refFrame, refView,
			currMbX, currMbY,
			currFrame, currView,
			blkSize
			);
	std::string str(traceObj);
	return str;
}
void MemTracingFile::saveInTraceFile() {
	std::string traceObj = toString();
	fprintf(traceFile,"%s",traceObj.c_str());
}

void MemTracingFile::saveInTraceFileBin() {
	fwrite(&refMinX, sizeof(int), 1, traceFile);
	fwrite(&refMinY, sizeof(int), 1, traceFile);
	fwrite(&refMaxX, sizeof(int), 1, traceFile);
	fwrite(&refMaxY, sizeof(int), 1, traceFile);
	fwrite(&refFrame, sizeof(int), 1, traceFile);
	fwrite(&refView, sizeof(int), 1, traceFile);
	fwrite(&currMbX, sizeof(int), 1, traceFile);
	fwrite(&currMbY, sizeof(int), 1, traceFile);
	fwrite(&currFrame, sizeof(int), 1, traceFile);
	fwrite(&currView, sizeof(int), 1, traceFile);
	fwrite(&blkSize, sizeof(int), 1, traceFile);
	fwrite(&biPrediction, sizeof(char), 1, traceFile);
        fwrite(&refinement, sizeof(char), 1, traceFile);
}

unsigned int MemTracingFile::getRefFrame() {
	return refFrame;
}

unsigned int MemTracingFile::getRefView() {
	return refView;
}

std::string MemTracingFile::getAreaRef() {
	char str[50];
	sprintf(str,"(%d,%d)(%d,%d) %c\n", refMinX, refMinY, refMaxX, refMaxY, refinement);
	std::string returnable(str);
	return returnable;
}

void MemTracingFile::setRefinement(char c) {
    refinement = c;
}

void MemTracingFile::printMbStartPoint(int x, int y) {
    fprintf(startPointsFile,"Mb(%d,%d) (%d,%d) -- %d,%d\n",currMbX, currMbY, refView, refFrame, x, y);

}

