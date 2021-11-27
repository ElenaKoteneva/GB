#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <algorithm>

using namespace std;

class Card
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true)
        :m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
    {}

    uint16_t GetValue() const
    {
        uint16_t value = 0;
        if (m_IsFaceUp)
        {
            value = m_Rank;
            if (value > 10)
            {
                value = 10;
            }
        }
        return value;
    }

    void Flip()
    {
        m_IsFaceUp = !(m_IsFaceUp);
    }

    friend ostream& operator<<(ostream& os, const Card& aCard);

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

ostream& operator<< (ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }
    return os;
}

class Hand
{
public:
    Hand()
    {
        m_Cards.reserve(7);
    }

    virtual ~Hand()
    {
        Clear();
    }

    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }

    void Clear()
    {
        // проходит по вектору, освобождая всю память в куче
        vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete *iter;
            *iter = 0;
        }
        // очищает вектор указателей
        m_Cards.clear();
    }

    uint16_t GetTotal() const
    {
        // если карт в руке нет, возвращает 0
        if (m_Cards.empty())
        {
            return 0;
        }
        // если первая карта имеет значение 0, то она лежит рубашкой вверх:
        // вернуть 0
        if (m_Cards[0]->GetValue() == 0)
        {
            return 0;
        }
        // находит сумму очков всех карт, каждый туз дает одно очко
        uint16_t total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            total += (*iter)->GetValue();
        }
        // определяет, держит ли рука туз
        bool containsAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            if ((*iter)->GetValue() == Card::ACE)
            {
                containsAce = true;
            }
        }
        // если рука держит туз и сумма довольно маленькая,  то туз дает 11 очков
        if (containsAce && total <= 11)
        {
            // добавляем только 10 очков, поскольку мы уже добавили
            // за каждый туз по 1 очку
            total += 10;
        }
        return total;
    }
protected:
    vector<Card*> m_Cards;
};

class GenericPlayer : public Hand
{
    friend ostream& operator<< (ostream& out, const GenericPlayer& aGenericPlayer);

protected:
    string m_Name;

public:

    GenericPlayer(const string& _name = "")
                :m_Name(_name)
    {}

    virtual ~GenericPlayer()
    {}

    // Показывает, хочет ли игрок продолжать брать карты.
    // Для класса GenericPlayer функция не имеет своей реализации,
    // т.к. для игрока и дилера это будут разные функции.
    virtual bool IsHitting() const = 0;

    // Возвращает значение, если у игрока перебор - сумму очков большую 21.
    // Данная функция не виртуальная, т.к. имеет одинаковую реализацию для игрока и дилера.
    virtual bool IsBoosted() const
    {
        return (GetTotal() > 21);
    }

    // Объявляет, что игрок имеет перебор.
    // Функция одинакова как для игрока, так и для дилера
    void Bust() const
    {
        cout << m_Name << " Boost.\n";
    }
};

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }

        if (aGenericPlayer.GetTotal() != 0)
        {
            cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}

class Player : public GenericPlayer
{
public:
    Player(const string& _name = "")
    {
        m_Name = _name;
//        setName(_ame);
    }

    virtual ~Player()
    {}

    // Показывает, хочет ли игрок продолжать брать карты.
    virtual bool IsHitting() const override
    {
        cout << m_Name << ", do you want a hit? (Y(y)/N(n)): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    // Объявляет, что игрок победил.
    void Win() const
    {
        cout << m_Name << " wins.\n";
    }

    // Объявляет, что игрок проиграл.
    void Lose() const
    {
        cout << m_Name << " loses.\n";
    }

    // Объявляет ничью.
    void Push() const
    {
        cout << m_Name << " pushes.\n";
    }
};

class House : public GenericPlayer
{
public:
    House(const string& _name = "House")
    {
        m_Name = _name;
        //setName(_name);
    }

    virtual ~House()
    {}

    // Показывает, хочет ли дилер продолжать брать карты.
    virtual bool IsHitting() const override
    {
        return (GetTotal() <= 16);
    }

    // Переворачивает первую карту.
    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
        {
            m_Cards[0]->Flip();
        }
        else
        {
            cout << "No card to flip!\n";
        }
    }
};

class Deck : public Hand
{
public:
    Deck()
    {
        m_Cards.reserve(52);
        Populate();
    }

    virtual ~Deck() {}

    // создает стандартную колоду из 52 карт
    void Populate()
    {
        Clear();
        // создает стандартную колоду
        for (uint8_t s = Card::CLUBS; s <= Card::SPADES; ++s)
        {
            for (uint8_t r = Card::ACE; r <= Card::KING; ++r)
            {
                Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
            }
        }
    }

    // тасует карты
    void Shuffle()
    {
        random_shuffle(m_Cards.begin(), m_Cards.end());
    }

    // раздает одну карту в руку
    void Deal(Hand& aHand)
    {
        if (!m_Cards.empty())
        {
            aHand.Add(m_Cards.back());
            m_Cards.pop_back();
        }
        else
        {
            cout << "Out of cards. Unable to deal.";
        }
    }

    // дает дополнительные карты игроку
    void AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        cout << endl;
        // продолжает раздавать карты до тех пор, пока у игрока не случается
        // перебор или пока он хочет взять еще одну карту
        while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
            cout << aGenericPlayer << endl;

            if (aGenericPlayer.IsBoosted())
            {
                aGenericPlayer.Bust();
            }
        }
    }
};

/* 4. Реализовать класс Game, который представляет собой основной процесс игры. У этого класса будет 3 поля:
колода карт
рука дилера
вектор игроков.
Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
В конструкторе создается колода карт и затем перемешивается.
Также класс имеет один метод play(). В этом методе раздаются каждому игроку по две стартовые карты,
а первая карта дилера прячется. Далее выводится на экран информация о картах каждого игра, в т.ч. и для
дилера. Затем раздаются игрокам дополнительные карты. Потом показывается первая карта дилера и дилер
набирает карты, если ему надо. После этого выводится сообщение, кто победил, а кто проиграл.
В конце руки всех игроков очищаются.*/

class Game
{
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
public:
// Конструктор этого класса принимает ссылку на вектор строк, представляющих
// имена игроков-людей. Конструктор создает объект класса Player для каждого имени
    Game(const vector<string>& names)
    {
        // создает вектор игроков из вектора с именами
        vector<string>::const_iterator pName;

        for (pName = names.begin(); pName != names.end(); ++pName)
        {
            m_Players.push_back(Player(*pName));

        }/*
        for (uint8_t i = 0; i < numPlayers; ++i)
        {
            m_Players.push_back(names[i]);
            cout << m_Players[i].getName() << " " << endl;
        }*/

        srand(static_cast<unsigned int>(time(0)));
        m_Deck.Populate();
        m_Deck.Shuffle();

    }

    ~Game() {}

    void Play()
    {
        // раздает каждому по две стартовые карты
        vector<Player>::iterator pPlayer;

        for (uint8_t i = 0; i < 2; ++i)
        {
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            {
                m_Deck.Deal(*pPlayer);
            }
            m_Deck.Deal(m_House);
        }
        // прячет первую карту дилера
        m_House.FlipFirstCard();
        // открывает руки всех игроков
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            cout << *pPlayer << endl;
        }
        cout << m_House << endl;
        // раздает игрокам дополнительные карты
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.AdditionalCards(*pPlayer);
        }
        // показывает первую карту дилера
        m_House.FlipFirstCard();
        cout << endl << m_House;
        // раздает дилеру дополнительные карты
        m_Deck.AdditionalCards(m_House);

        if (m_House.IsBoosted())
        {
            // все, кто остался в игре, побеждают
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            {
                if (!(pPlayer->IsBoosted()))
                {
                    pPlayer->Win();
                }
            }
        }
        else
        {
            // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
                 ++pPlayer)
            {
                if (!(pPlayer->IsBoosted()))
                {
                    if (pPlayer->GetTotal() > m_House.GetTotal())
                    {
                        pPlayer->Win();
                    }
                    else if (pPlayer->GetTotal() < m_House.GetTotal())
                    {
                        pPlayer->Lose();
                    }
                    else
                    {
                        pPlayer->Push();
                    }
                }
            }

        }
        // очищает руки всех игроков
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            pPlayer->Clear();
        }
        m_House.Clear();
    }
};

int main()
{

    cout << "\t\tWelcome to Blackjack!\n\n";
    int numPlayers = 0;
/*
    vector<string> names;
    string name;
    names.push_back("Elena");
    names.push_back("Alena");
    Player p1("Alena");
    cout << p1.getName();
    */

    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;




    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

return 0;
}
