import FWCore.ParameterSet.Config as cms

process = cms.Process("MakeNpKNU")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )
process.MessageLogger.cerr.FwkReport.reportEvery=100


process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/hcp/data/data02/jwkim2/store/mc/RunIISummer16MiniAODv2/701979BD-51C4-E611-9FC9-C4346BC84780.root'
    )
)

process.MakeNpKNU = cms.EDAnalyzer('MakeNpKNU',
	electrons = cms.InputTag("slimmedElectrons")
)


process.p = cms.Path(process.MakeNpKNU)
