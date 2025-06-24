// ======================================================================
// \title  HelloWorld.cpp
// \author easymatt90
// \brief  cpp file for HelloWorld component implementation class
// ======================================================================

#include "Components/HelloWorld/HelloWorld.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  HelloWorld ::
    HelloWorld(const char* const compName) :
      HelloWorldComponentBase(compName),
      m_greetingCount(0)
  {

  }

  HelloWorld ::
    ~HelloWorld()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void HelloWorld ::
    SAY_HELLO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        const Fw::CmdStringArg& greeting
    )
  {
    // Copy the command string input into an event string for the Hello event
    Fw::LogStringArg eventGreeting(greeting.toChar());

    // Emit the Hello event with the copied string
    this->log_ACTIVITY_HI_Hello(eventGreeting);

    // Increment and send telemetry
    this->tlmWrite_GreetingCount(++this->m_greetingCount);

    // Tell the fprime command system that we have completed the processing
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
