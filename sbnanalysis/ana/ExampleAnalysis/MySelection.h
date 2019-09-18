#ifndef __sbnanalysis_ana_ExampleAnalysis_MySelection__
#define __sbnanalysis_ana_ExampleAnalysis_MySelection__

/**
 * \file MySelection.h
 *
 * An example event selection processor.
 *
 * This is an implementation of the core::SelectionBase class. We define
 * the methods called for initialization, finalization, and event-by-event
 * processing.
 *
 * Author: A. Mastbaum <mastbaum@uchicago.edu>
 */

// Includes
#include <iostream>
#include "canvas/Utilities/InputTag.h"
#include "core/SelectionBase.hh"
#include "core/Event.hh"

// Forward declarations
class TH2D;

/** All analysis code is defined in namespace "ana" */
namespace ana {

  /** Code specific to the ExampleAnalysis. */
  namespace ExampleAnalysis {

/**
 * \class MySelection
 * \brief An example selection analysis
 *
 * This selection analysis doesn't actually select events, it just
 * demonstrates the framework!
 */
class MySelection : public core::SelectionBase {
public:
  /** Constructor. */
  MySelection();

  /**
   * Initialization.
   *
   * Here we load configuration parameters, set up histograms for output, and
   * add our own branches to the output tree.
   *
   * \param config A configuration, as FHiCL ParameterSet object
   */
  void Initialize(fhicl::ParameterSet* config=NULL);

  /** Finalize and write objects to the output file. */
  void Finalize();

  /**
   * Process one event.
   *
   * \param ev A single event, as a gallery::Event
   * \param reco Reconstructed interactions
   * \return True to keep event
   */
  bool ProcessEvent(const gallery::Event& ev,
                    const std::vector<event::Interaction>& truth,
                    std::vector<event::RecoInteraction>& reco);

protected:
  unsigned fEventCounter;  //!< Count processed events

  /** Configuration parameters */
  art::InputTag fTruthTag;  //!< art tag for MCTruth information

  /** Custom data branches */
  int fNuCount;  //!< Number of neutrino interactions in the event

  /** Histograms */

};

  }  // namespace ExampleAnalysis
}  // namespace ana

#endif  // __sbnanalysis_ana_ExampleAnalysis_MySelection__

