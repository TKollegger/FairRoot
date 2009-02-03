#ifndef FAIRGEOASCIIIO_H
#define FAIRGEOASCIIIO_H

#include "FairGeoIo.h"

#include "TString.h"

#include <fstream>
//#include <iomanip>

class FairGeoSet;
class FairGeoMedia;
class FairGeoInterface;

/**
 * Class for geometry I/O from ASCII file
 * @author Ilse Koenig 
 */
class FairGeoAsciiIo: public FairGeoIo {
  TString  filename;
  TString  filedir;
  Bool_t   writable;
  fstream* file;
public:
  FairGeoAsciiIo();
  virtual ~FairGeoAsciiIo();
  void setDirectory(const char* fDir) {filedir=fDir;}
  const char* getDirectory() {return filedir.Data();}
  const char* getFilename() {return filename.Data();}
  Bool_t open(const char*,const Text_t* status="in");
  Bool_t isOpen();
  Bool_t isWritable();
  void close();
  void print();
  Bool_t read(FairGeoMedia*);
  Bool_t read(FairGeoSet*,FairGeoMedia*);
  Bool_t write(FairGeoMedia*);
  Bool_t write(FairGeoSet* set);
  Bool_t readGeomConfig(FairGeoInterface*);
  Bool_t readDetectorSetup(FairGeoInterface*);
  Bool_t setSimulRefRun(const char*) {return kTRUE;}
  Bool_t setHistoryDate(const char*) {return kTRUE;}
private:
  FairGeoAsciiIo(const FairGeoAsciiIo &L);
  FairGeoAsciiIo& operator= (const FairGeoAsciiIo&) {return *this;}
  ClassDef(FairGeoAsciiIo,0) // Class for geometry I/O from ASCII file
};

#endif  /* !FAIRGEOASCIIIO_H */