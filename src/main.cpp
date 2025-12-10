#include <Geode/Geode.hpp>
#include <Geode/modify/RateStarsLayer.hpp>

using namespace geode::prelude;

class $modify(RateStarsLayer) {
	$override
	void selectRating(CCObject* sender) {
		RateStarsLayer::selectRating(sender);

		auto level = GameLevelManager::get()->getSavedLevel(m_levelID);
		int requested = level->m_starsRequested;
		if(requested <=0 || requested > 10) return;
		static_cast<ButtonSprite*>(
			static_cast<CCMenuItemSpriteExtra*>(m_buttons->objectAtIndex(requested - 1))->getNormalImage()
		)->setColor({0, 255, 0});
	}
};
