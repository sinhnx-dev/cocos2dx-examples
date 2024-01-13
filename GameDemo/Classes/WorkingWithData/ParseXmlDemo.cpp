#include "ParseXmlDemo.h"

USING_NS_CC;
using namespace std;
using namespace tinyxml2;

ParseXmlDemo::ParseXmlDemo() {}
ParseXmlDemo::ParseXmlDemo(std::string filePath)
{
    path = cocos2d::FileUtils::getInstance()->fullPathForFilename(filePath);
    // log("%s\n", cocos2d::FileUtils::getInstance()->fullPathForFilename(filePath).c_str());
}

vector<playerUser> ParseXmlDemo::loadLeaderBoard(int no)
{
    vector<playerUser> users = vector<playerUser>();
    std::string content = cocos2d::FileUtils::getInstance()->getStringFromFile(path.c_str());
    // log("%s", content.c_str());
    doc.Parse(content.c_str());
    tinyxml2::XMLHandle docHandle(&doc);
    tinyxml2::XMLElement *entry = docHandle.FirstChildElement("ranking").ToElement();

    if (entry)
    {
        for (tinyxml2::XMLNode *node = entry->FirstChildElement(); node; node = node->NextSibling())
        {
            tinyxml2::XMLElement *e = node->ToElement();
            const char *name = e->Attribute("user_name");
            int scores = e->IntAttribute("scores");
            if (name)
            {
                playerUser u;
                u.userName = std::string(name);
                u.score = scores;
                users.push_back(u);
            }
        }
    }
    else
    {
        log("can't parse xml");
    }

    return users;
}

bool ParseXmlDemo::insertLeaderBoard(playerUser u)
{
    tinyxml2::XMLError eResult = doc.LoadFile(path.c_str());
    if (eResult != tinyxml2::XML_SUCCESS)
    {
        log("can't load file");
        return false;
    }
    // Get root Element
    XMLNode *root = doc.FirstChildElement();
    if (root == nullptr)
    {
        log("can't load root document");
        return false;
    }
    XMLElement *newUser = doc.NewElement("user");
    newUser->SetAttribute("user_name", u.userName.c_str());
    newUser->SetAttribute("scores", u.score);
    root->InsertEndChild(newUser);
    eResult = doc.SaveFile(path.c_str(), false);
    return eResult == tinyxml2::XML_SUCCESS;
}
bool ParseXmlDemo::saveToFile(std::vector<playerUser> users)
{
    tinyxml2::XMLError eResult = doc.LoadFile(path.c_str());
    if (eResult != tinyxml2::XML_SUCCESS)
    {
        log("can't load file");
        return false;
    }
    // Get root Element
    XMLNode *root = doc.FirstChildElement();
    if (root == nullptr)
    {
        log("can't load root document");
        return false;
    }
    // Delete children
    root->DeleteChildren();
    for (const playerUser u : users)
    {
        XMLElement *newUser = doc.NewElement("user");
        newUser->SetAttribute("user_name", u.userName.c_str());
        newUser->SetAttribute("scores", u.score);
        root->InsertEndChild(newUser);
    }
    eResult = doc.SaveFile(path.c_str(), false);
    return eResult == tinyxml2::XML_SUCCESS;
}