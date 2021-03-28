/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** ChatBox
*/

#include "ChatBox.hpp"

ChatBox::ChatBox()
{
    _font.loadFromFile("src/fonts/RetroGaming.ttf");
    sf::Text tmp;
    tmp.setFont(_font);
    tmp.setFillColor(sf::Color::White);
    tmp.setCharacterSize(20);
    for (size_t i = 0; i < 5; i++) {
        _dialog.push_back(tmp);
        _dialog[i].setPosition(sf::Vector2f{200, 890 + ((float)i * 30)});
    }
    std::string str("");
    for (size_t i = 0; i < 5; i++) {
        _msg.push_back(str);
    }
    _box.setSize(sf::Vector2f{1900, 200});
    _box.setPosition(sf::Vector2f{10, 870});
    _box.setOutlineThickness(3.0);
    _box.setOutlineColor(sf::Color::White);
    _box.setFillColor(sf::Color::Black);
    textClock.restart();
    _lines = 0;
    _isOpen = false;
    newline = false;
    _isFinished = true;
    read = true;
    allLine = false;
}

ChatBox::~ChatBox()
{
}

void ChatBox::setLanguage(std::string language)
{
    lang = language;
}

void ChatBox::setPositions(sf::IntRect r)
{
    for (size_t i = 0; i < 5; i++) {
        _dialog[i].setPosition(sf::Vector2f{(float)r.left + 200, (float)r.height - 180 + ((float)i * 30)});
    }
    _box.setPosition(sf::Vector2f{(float)r.left + 10, (float)r.height - 200});
    _sprite.setPosition(sf::Vector2f{(float)r.left + 40, (float)r.height - 180});
}

void ChatBox::loadSprite(const std::string &texturePath)
{
    _texture.loadFromFile(texturePath);
    _sprite.setTexture(_texture);
}

sf::RectangleShape ChatBox::getBox() const
{
    return _box;
}

void ChatBox::readMessage(const std::string &msgPath)
{
    _file.open(msgPath + lang, std::ios::in);
    _isOpen = true;
    _isFinished = false;
    for (int i = 0; i < 5; i++) {
        _msg[i].clear();
    }
    _lines = 0;
}

char ChatBox::readLetter()
{
    char c;
    if (!read)
        return 0;
    if (!_file.eof()){
        _file.get(c);
        return c;
    }
    _isFinished = true;
    _file.close();
    return 0;
}

void ChatBox::draw(sf::RenderWindow *w)
{
    w->draw(_box);
    for (size_t i = 0; i < 5; i++) {
        w->draw(_dialog[i]);
    }
    w->draw(_sprite);
}

void ChatBox::addLine()
{
    newline = true;
    if (!allLine)
        allLine = true;
    else if (allLine)
        allLine = false;
    if (_isFinished) {
        _isOpen = false;
        allLine = false;
    }
}

std::vector<sf::Text> ChatBox::getDialog() const
{
    return _dialog;
}

std::string ChatBox::readLine(std::string msg)
{
    if (!read)
        return msg;
    char c = readLetter();
    if (c == 0)
        return msg;
    if (c == '\n') {
        _lines += 1;
        if (_lines > 4)
            read = false;
        return msg;
    }
    msg += c;
    if (allLine)
        msg = readLine(msg);
    return msg;
}

void ChatBox::setDialog()
{
    if (textClock.getElapsedTime().asSeconds() >= 0.05) {
        if (!_isFinished) {
            if (_lines < 5) {
                if (_lines == 0)
                    _msg[0] = readLine(_msg[0]);
                else if (_lines == 1)
                    _msg[1] = readLine(_msg[1]);
                else if (_lines == 2)
                    _msg[2] = readLine(_msg[2]);
                else if (_lines == 3)
                    _msg[3] = readLine(_msg[3]);
                else if (_lines == 4)
                    _msg[4] = readLine(_msg[4]);
                _dialog[0].setString(_msg[0]);
                _dialog[1].setString(_msg[1]);
                _dialog[2].setString(_msg[2]);
                _dialog[3].setString(_msg[3]);
                _dialog[4].setString(_msg[4]);
                allLine = false;
            }
            else {
                if (newline) {
                    read = true;
                    _dialog[0].setString(_msg[1]);
                    _dialog[1].setString(_msg[2]);
                    _dialog[2].setString(_msg[3]);
                    _dialog[3].setString(_msg[4]);
                    _msg[0].clear();
                    _msg[0] += _msg[1];
                    _msg[1].clear();
                    _msg[1] += _msg[2];
                    _msg[2].clear();
                    _msg[2] += _msg[3];
                    _msg[3].clear();
                    _msg[3] += _msg[4];
                    _msg[4].clear();
                    _msg[4] = readLine(_msg[4]);
                    _dialog[4].setString(_msg[4]);
                    newline = false;
                    allLine = false;
                }
                else {
                    _msg[4] = readLine(_msg[4]);
                    _dialog[4].setString(_msg[4]);
                }
            }
        }
        textClock.restart();
    }
}

bool ChatBox::isOpen() const
{
    return (_isOpen);
}