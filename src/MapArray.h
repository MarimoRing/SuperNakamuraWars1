#pragma once
#include <vector>
#include "Task.h"
#include "Enum.h"
#include "Define.h"

/*!
@brief マップ上でキャラクターの有無と敵味方を判断する
*/
class MapArray final : public Task
{
public:
	MapArray();
	~MapArray() = default;
	bool update() override;
	void draw() const override;

private:
	void enemy();
	void Friend();
	void calculation(int _x, int _y);
	std::vector<MapState> _mapState;
};