#ifndef ROOT_LS_H
#define ROOT_LS_H

#include "TaskRunner.h"

#include "TFile.h"
#include "vendor/loguru.h"

class RootLS : public TaskRunner {

public:

    virtual void init(){
    }

    virtual void make(){
        for ( int i = 0; i < config.getInt( "argc" ); i++ ){
            string argv = config["arg[" + ts(i) + "]"];
            // LOG_F( INFO, "--arg[%d]=%s", i, argv.c_str() );
            if ( i < 1 )
                continue;
            TFile * f = new TFile( argv.c_str(), "READ" );
            if ( f->IsOpen() == false ){
                LOG_F( INFO, "%s DNE", argv.c_str() );
                continue;
            }
            f->ls();
            cout << endl;

        }
        
    }

};




#endif