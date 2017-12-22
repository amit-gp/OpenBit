#include "includes/globalvariables.h"

GlobalVariables* GlobalVariables::mInstance = nullptr;

GlobalVariables* GlobalVariables::Instance(){

    if(mInstance == nullptr){
        mInstance = new GlobalVariables;
    }
    return mInstance;
}
