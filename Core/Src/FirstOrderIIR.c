/*
 * FirstOrderIIR.c
 *
 *  Created on: 13 maj 2022
 *      Authors: Dawid Łukasiewicz and Martyna Żukowska
 */

#include "FirstOrderIIR.h"

int FirstOrderIIR_Init(FirstOrderIIR_t *filter, float alpha, float beta_0, float beta_1)
{
	if(alpha > 1.0f || alpha < 0.0f)
		return -1;

	filter->alpha = alpha;
	filter->beta_0 = beta_0;
	filter->beta_1 = beta_1;
	filter->out = 0.0f;
	filter->previous_in = 0.0f;

	return 0;
}

float FirstOrderIIR_Update(FirstOrderIIR_t *filter, float in)
{
	filter->out = filter->beta_0 + in + filter->beta_1 * filter->previous_in + filter->alpha * filter->out;
	filter->previous_in = in;

	return filter->out;
}
