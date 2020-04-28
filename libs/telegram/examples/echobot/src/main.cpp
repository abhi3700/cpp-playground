// // #include <stdio.h>
// #include <iostream>
// #include <tgbot/tgbot.h>

// using std::string;
// using namespace TgBot;

// const string TOKEN = "1203919333:AAHs0PBuNA4rqQH9ZDmP7IXroNMoAWub7oE";

// int main() {
// 	TgBot::Bot bot("1203919333:AAHs0PBuNA4rqQH9ZDmP7IXroNMoAWub7oE");
//     bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
//         bot.getApi().sendMessage(message->chat->id, "Hi!");
//     });

    
// 	return 0;
// }

#include <stdio.h>
#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("1203919333:AAHs0PBuNA4rqQH9ZDmP7IXroNMoAWub7oE");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}