#include "SigmoidNormalizerFunction.h"

#include <math.h>

double SigmoidNormalizerFunction::NormalizeValue(double value)
{
    return 1/(1+exp(-value));
}