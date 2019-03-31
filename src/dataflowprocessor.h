#ifndef _SF_DATA_FLOW_
#define _SF_DATA_FLOW_
#include <sinsp.h>
#include "sysflowcontext.h"
#include "op_flags.h"
#include "networkflowprocessor.h"
#include "sysflowwriter.h"

namespace dataflow {
    class DataFlowProcessor {
        private:
           networkflow::NetworkFlowProcessor* m_netflowPrcr;
           SysFlowContext*   m_cxt;
           DataFlowSet m_dfSet;
           time_t m_lastCheck;
        public:
           inline int getSize() {
               return m_netflowPrcr->getSize();
           }
           int handleDataEvent(sinsp_evt* ev, OpFlags flag);
           DataFlowProcessor(SysFlowContext* cxt, SysFlowWriter* writer, process::ProcessContext* processCxt);
           virtual ~DataFlowProcessor();
           void clearTables();
           int checkForExpiredRecords();
           int removeAndWriteDFFromProc(ProcessObj* proc);
    };
}

#endif