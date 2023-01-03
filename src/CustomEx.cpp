#include "CustomEx.h"

String^ CustomEx::getMessage()
{
    return marshal_as<String^>(message);
}
