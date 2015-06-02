// -*- C++ -*-
//
// $Id$
#ifndef DATAREADER_LISTENER_IMPL
#define DATAREADER_LISTENER_IMPL

#include "dds/DdsDcpsSubscriptionExtC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DCPS/LocalObject.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


//Class DataReaderListenerImpl
class DataReaderListenerImpl
  : public virtual OpenDDS::DCPS::LocalObject<OpenDDS::DCPS::DataReaderListener>
{
public:
  //Constructor
  DataReaderListenerImpl (void);

  //Destructor
  virtual ~DataReaderListenerImpl (void);

  virtual void on_requested_deadline_missed (
    ::DDS::DataReader_ptr reader,
    const ::DDS::RequestedDeadlineMissedStatus & status
  );

 virtual void on_requested_incompatible_qos (
    ::DDS::DataReader_ptr reader,
    const ::DDS::RequestedIncompatibleQosStatus & status
  );

  virtual void on_liveliness_changed (
    ::DDS::DataReader_ptr reader,
    const ::DDS::LivelinessChangedStatus & status
  );

  virtual void on_subscription_matched (
    ::DDS::DataReader_ptr reader,
    const ::DDS::SubscriptionMatchedStatus & status
  );

  virtual void on_sample_rejected(
    ::DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& status
  );

  virtual void on_data_available(
    ::DDS::DataReader_ptr reader
  );

  virtual void on_sample_lost(
    ::DDS::DataReader_ptr reader,
    const DDS::SampleLostStatus& status
  );

  virtual void on_subscription_disconnected (
      ::DDS::DataReader_ptr reader,
      const ::OpenDDS::DCPS::SubscriptionDisconnectedStatus & status
    );

  virtual void on_subscription_reconnected (
      ::DDS::DataReader_ptr reader,
      const ::OpenDDS::DCPS::SubscriptionReconnectedStatus & status
    );

  virtual void on_subscription_lost (
      ::DDS::DataReader_ptr reader,
      const ::OpenDDS::DCPS::SubscriptionLostStatus & status
    );

  virtual void on_budget_exceeded (
      ::DDS::DataReader_ptr,
      const ::OpenDDS::DCPS::BudgetExceededStatus& status
    );

  virtual void on_connection_deleted (
    ::DDS::DataReader_ptr
    );

  int liveliness_changed_count() const { return liveliness_changed_count_ ; }
  void reset_liveliness_changed_count(){ liveliness_changed_count_ = 0 ; }

  CORBA::Long no_writers_generation_count() const
  {
    return last_si_.no_writers_generation_count ;
  }

  bool verify_last_liveliness_status ()
  {
    return last_status_.alive_count == 0 && last_status_.not_alive_count == 0;
  }

private:
  int liveliness_changed_count_ ;
  ::DDS::SampleInfo last_si_ ;

  ::DDS::LivelinessChangedStatus last_status_;
};

#endif /* DATAREADER_LISTENER_IMPL  */
