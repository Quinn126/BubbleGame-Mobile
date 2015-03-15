#include "GameScene.h"
#include "SimpleAudioEngine.h" 

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto backgroundSprite = Sprite::create("iphone/Background.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(backgroundSprite);

    int x = backgroundSprite->getContentSize().width;
    int y = backgroundSprite->getContentSize().height;
    auto *menu = Menu::create();
    menu->setPosition(Point(origin.x + x/3, origin.y + y/7));
    menu->setScale(0.5, 0.9);
    this->addChild(menu);
    
   for(int i = 15; i > 5; i = i-1){
     for(int p = 50; p > 5; p = p-1){
         auto mySprite = Sprite::create("iphone/bubble.png");
         mySprite->setPosition(Point(((x/5) * i), ((y/5) * p)));
         mySprite->setScale(0.05);
         auto menu_item = MenuItemSprite::create(mySprite, mySprite, mySprite, CC_CALLBACK_1(GameScene::ImageButton,this));
         menu_item->setPosition(Point(visibleSize.width/i, visibleSize.height/p));
         menu->addChild(menu_item);
      }
    }
    
    return true;
}

void GameScene::ImageButton(cocos2d::Ref *pSender){
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playEffect("iphone/shoot.wav", false, 1.0f, 1.0f, 1.0f);
    CCLOG("Image Button");
}


