
#include "bionetsolver/BionetworkTemplateLibrary.h"
#include "bionetsolver/BionetworkSBML.h"

//BionetworkTemplateLibrary::BionetworkTemplateLibrary() : typeName("") {}
BionetworkTemplateLibrary::BionetworkTemplateLibrary() : templateLibraryName("") {}
BionetworkTemplateLibrary::~BionetworkTemplateLibrary() {}
//BionetworkTemplateLibrary::BionetworkTemplateLibrary(std::string _cellTypeName) : typeName(_cellTypeName) {}
BionetworkTemplateLibrary::BionetworkTemplateLibrary(std::string _newTemplateLibraryName) : 
    templateLibraryName(_newTemplateLibraryName) {}

bool BionetworkTemplateLibrary::hasSBMLModelByKey(std::string modelKey) const {
    bool sbmlModelKeyFound = false;
    //std::map<std::string, const BionetworkSBML *>::const_iterator it = intracellularModels.begin();
    std::map<std::string, const BionetworkSBML *>::const_iterator it = bionetworkModels.begin();
    //for(; it != intracellularModels.end(); ++it)
    for(; it != bionetworkModels.end(); ++it)
        if( it->second->getModelKey() == modelKey ){
            sbmlModelKeyFound = true;
            break;
        }
    return sbmlModelKeyFound;
}

void BionetworkTemplateLibrary::addSBMLModel(const BionetworkSBML *newModel){
    //intracellularModels[newModel->getModelName()] = newModel;
    bionetworkModels[newModel->getModelName()] = newModel;
}

const BionetworkSBML *BionetworkTemplateLibrary::getSBMLModelByName(std::string modelName) const {
    const BionetworkSBML *model = NULL;
    std::map<std::string, const BionetworkSBML *>::const_iterator itr;
    //for(itr = intracellularModels.begin(); itr != intracellularModels.end(); ++itr){
    for(itr = bionetworkModels.begin(); itr != bionetworkModels.end(); ++itr){
        if(itr->first == modelName){ 
            model = itr->second;
            break;
        }
    }
    return model;
}

const BionetworkSBML * BionetworkTemplateLibrary::getSBMLModelByKey(std::string modelKey) const {
    const BionetworkSBML *model = NULL;
    std::map<std::string, const BionetworkSBML *>::const_iterator itr;
    //for(itr = intracellularModels.begin(); itr != intracellularModels.end(); ++itr){
    for(itr = bionetworkModels.begin(); itr != bionetworkModels.end(); ++itr){
        if(itr->second->getModelKey() == modelKey){
            model = itr->second;
            break;
        }
    }
    return model;
}

std::vector<std::string> BionetworkTemplateLibrary::getModelNames() const {
    std::vector<std::string> modelNames;
    //std::map<std::string, const BionetworkSBML *>::const_iterator itr = intracellularModels.begin();
    std::map<std::string, const BionetworkSBML *>::const_iterator itr = bionetworkModels.begin();
    //for(; itr != intracellularModels.end(); ++itr){
    for(; itr != bionetworkModels.end(); ++itr){
        modelNames.push_back(itr->first);
    }
    return modelNames;
}

std::string BionetworkTemplateLibrary::getModelNamesAsString() const {
    std::string modelNames;
    //std::map<std::string, const BionetworkSBML *>::const_iterator itr = intracellularModels.begin();
    std::map<std::string, const BionetworkSBML *>::const_iterator itr = bionetworkModels.begin();
    //for(; itr != intracellularModels.end(); ++itr){
    for(; itr != bionetworkModels.end(); ++itr){
        modelNames+=itr->first+" ";
    }
    return modelNames;
}

/* void BionetworkTemplateLibrary::setInitialCondition(
    std::string varType, std::string variableName, double variableValue){
    
    if( varType == "SBML" ){
        sbmlInitialConditions[variableName] = variableValue;
    }
    
    if( varType == "CC3D" ){
        cc3dInitialConditions[variableName] = variableValue;
    }
 } */
 
 void BionetworkTemplateLibrary::setInitialCondition(
    std::string variableName, double variableValue){
    
    sbmlInitialConditions[variableName] = variableValue;
 } 

/*std::map<std::string, double> 
BionetworkTemplateLibrary::getInitialConditions(std::string varType) const {
    std::map<std::string, double> initConditions;
    
    if( varType == "SBML" ){
        initConditions = sbmlInitialConditions;
    }
    if( varType == "CC3D" ){
        initConditions = cc3dInitialConditions;
    }
    
    return initConditions;
}
*/

std::map<std::string, double> 
BionetworkTemplateLibrary::getInitialConditions() const {
    return sbmlInitialConditions;
}




