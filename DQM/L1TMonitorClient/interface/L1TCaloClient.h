#ifndef L1TCaloClient_H
#define L1TCaloClient_H
// -*- C++ -*-
//
// Package:    L1TCaloClient
// Class:      L1TCaloClient
// 
/**\class L1TCaloClient L1TCaloClient.cc DQM/L1TCaloClient/src/L1TCaloClient.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Lorenzo Agostino
//         Created:  Thu Jun 28 11:32:01 CEST 2007
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"

#include "DQM/L1TClient/interface/L1TBaseClient.h"

//#include "DQMServices/Core/interface/MonitorUserInterface.h"
//
// class decleration
//

class L1TCaloClient : public edm::EDAnalyzer, public L1TBaseClient {
   public:
      explicit L1TCaloClient(const edm::ParameterSet&);
      ~L1TCaloClient();


   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      // ----------member data ---------------------------
      int nevents;

      DaqMonitorBEInterface *dbe;
      std::string outputFile;
      string MeanCriterionName;
      bool saveOutput;
      char hname[30];

      MonitorElement *MEprox;
      MonitorElement *MEproy;
      vector<MonitorElement *>  MEphiProfileFixedEta;
      vector<MonitorElement *>  MEDeadChannelReport;
       
};

#endif
