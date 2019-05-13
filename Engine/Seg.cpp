#include "Seg.h"
#include "Graphics.h"



Seg::Seg()
{
}


Seg::~Seg()
{
}
void Seg::Draw(int x, int y, Graphics & gfx, Color seg, Color gap)
{

	gfx.DrawRect((x * width), (y * height), width, height, gap);
	gfx.DrawRect((x * width) + segGap, (y * height) + segGap, width - (segGap * 2), height - (segGap * 2), seg);


}


