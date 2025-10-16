#include <Geode/Geode.hpp>
#include <Geode/modify/RateStarsLayer.hpp>

using namespace geode::prelude;

class $modify(RateStarsLayer) {
	$override
	bool init(int p0, bool p1, bool p2) {
		if (!RateStarsLayer::init(p0, p1, p2)) return false;

		auto level = GameLevelManager::get()->getSavedLevel(m_levelID);
		int requested = level->m_starsRequested;
		if(requested <=0 || requested > 10) return true;
		m_mainLayer->getChildByType<CCMenu>(0)
			->getChildByType<CCMenuItemSpriteExtra>(requested - 1)
			->getChildByType<ButtonSprite>(0)
			->setColor(ccColor3B(122, 127, 255));
		
		return true;
	}
};
