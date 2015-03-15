#include "GameScene.h"
#include "SimpleAudioEngine.h" 
#include "MainMenuScene.h"
#include "Definitions.h"

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
    
    
    
    
    auto backgroundSprite = Sprite::create("iphone/GameBackground.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(backgroundSprite);
    
    auto menu = Menu::create();
  
    Vector<cocos2d::MenuItem*> menuArray;
    
    for (int i = 11; i > 2; i--){
        for(int p = 9; p > 1; p--){
            auto bottomSprite = Sprite::create("iphone/Mark.png");
            auto menu_item = MenuItemImage::create("iphone/bubble.png", "iphone/bubble.png",  CC_CALLBACK_1(GameScene::ImageButton,this));
            bottomSprite->setPosition(Point((origin.x - visibleSize.width/5 + (visibleSize.width/10) * i), origin.y + ((visibleSize.height/10) * p)));
            menu_item->setPosition(Point(((visibleSize.width/10) * i), ((visibleSize.height/10) * p)));
            bottomSprite->setScale(0.1);
            this->addChild(bottomSprite);
            menu_item->setScale(0.05);
            menuArray.pushBack(menu_item);
            menu->addChild(menu_item);
        }
    }
    
//    auto menu = Menu::createWithArray(menuArray);
    menu->setPosition(Point(origin.x - visibleSize.width/5, origin.y));
    this->addChild(menu);
    
    auto item= MenuItemFont::create("BackToMenu",CC_CALLBACK_1(GameScene::Prettyweird,this));
    MenuItemFont::setFontSize(20);
    MenuItemFont::setFontName("Helvetica");
    item->setColor(Color3B(255,255,255));
    
    auto themenu = Menu::create(item,NULL);
    themenu->setPosition(Point::ZERO);
    this->addChild(themenu);
    
 
    item->setPosition(Point((visibleSize.width/6)*5 + origin.x, (visibleSize.height/8) + origin.y));
    return true;
}


void GameScene::ImageButton(cocos2d::Ref *pSender){
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playEffect("iphone/shoot.wav");
    auto m = dynamic_cast<cocos2d::MenuItem *>(pSender);
    m->setVisible(false);
    CCLOG("Image Button");
}


void GameScene::Prettyweird(cocos2d::Ref *sender)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME,scene));
}
