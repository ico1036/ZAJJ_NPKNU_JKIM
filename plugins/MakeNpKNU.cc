// -*- C++ -*-
//
// Package:    MakeNpKNU/MakeNpKNU
// Class:      MakeNpKNU
// 
/**\class MakeNpKNU MakeNpKNU.cc MakeNpKNU/MakeNpKNU/plugins/MakeNpKNU.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Jiwoong Kim
//         Created:  Sun, 01 Sep 2019 23:40:57 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TTree.h"
#include "TH1D.h"
#include "vector"


//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class MakeNpKNU : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit MakeNpKNU(const edm::ParameterSet&);
      ~MakeNpKNU();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
    
	  virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

	  edm::EDGetTokenT<std::vector<pat::Electron>> electronToken_;
	  TTree* outTree;

	  std::vector<double> v_ele_pt;
	  
      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MakeNpKNU::MakeNpKNU(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");
   electronToken_  = consumes<std::vector<pat::Electron>>(iConfig.getParameter<edm::InputTag>("electrons"));

}


MakeNpKNU::~MakeNpKNU()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MakeNpKNU::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif


	edm::Handle<std::vector<pat::Electron>> electrons;
	iEvent.getByToken(electronToken_,electrons);


	for(const pat::Electron &el: *electrons){
		cout << el.pt() << endl;
		
	}

}





// ------------ method called once each job just before starting event loop  ------------
void 
MakeNpKNU::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
MakeNpKNU::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MakeNpKNU::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MakeNpKNU);
