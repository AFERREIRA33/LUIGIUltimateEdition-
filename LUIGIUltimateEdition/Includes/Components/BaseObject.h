#pragma once

#include "../Utils/RTTI.h"

class BaseObject : public RTTI
{
public:
    BaseObject() = default;
    virtual ~BaseObject() = default;

    virtual FClass GetClass() override {
        return FClass("BaseObject");
    }; 
    static FClass StaticClass() {
        return FClass("BaseObject");
    };;
private:
    const char* name;
};

