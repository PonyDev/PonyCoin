// Copyright 2016 PonyCoin Devs

#include "globalparams.h"

//////////////////////////////////////////////////////////////////////
///
/// Network Constants
///
//////////////////////////////////////////////////////////////////////

// network constants (used to be in netbase.cpp)

// random port number, not used much
unsigned short const TOR_PORT = 44544;

unsigned short const P2P_PORT = 14444;
unsigned short const P2P_PORT_TESTNET = 54444;

unsigned short const DEFAULT_PROXY = 9050;
unsigned short const DEFAULT_PROXY_TESTNET = 19050;

// rpc
unsigned short const RPC_PORT = 44441;
unsigned short const RPC_PORT_TESTNET = 44445;


//////////////////////////////////////////////////////////////////////
///
/// PoS Constants
///
//////////////////////////////////////////////////////////////////////
#if PROOF_MODEL == PURE_POS
// must have a last PoW block if it is to be pure PoS
// optional overlap between PoW and PoS
int LAST_POW_BLOCK = 25919;
int FIRST_POS_BLOCK = 25920;
int LAST_WHITEPONY_BLOCK = 46080;
#elif PROOF_MODEL == MIXED_POW_POS
//
#endif  // PROOF_MODEL


//////////////////////////////////////////////////////////////////////
///
/// Money Constants
///
//////////////////////////////////////////////////////////////////////

// make sure these are consistent with nStakeMinAge
// 10 min at 2 min block times
static const int nStakeMinConfirmationsTestnet = 5;
// 8 hr at 2 min block times
static const int nStakeMinConfirmations = 240;

static const int POW_DAYS = 42;

const int DAY_REWARDS[POW_DAYS] = {
              1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 4, 4,
              7461, 3730, 3730, 1865, 1865, 1865, 1865,
              466, 466, 466, 466, 466, 466, 466, 466,
              466, 466, 466, 466, 466, 466, 239};


// avoid counting zeros
const int64_t BASE_COIN = 100000000;
const int64_t BASE_CENT = 1000000;

// different currencies (colored coins) have different money supplies
// fees are charged in the currency of the transaction
// const int BASE_FEE_EXPONENT = 5;

// some systems will want to multiply coinage by an interest rate
// ponycoin has a fixed and money supply dependent rewards
// const bool COINAGE_DEPENDENT_POS = false;

// for qualified addresses with currency as name
std::string ADDRESS_DELIMETER = "_";

// different currencies may have different divisibilities
//                               -     PONY
const int64_t COIN[N_COLORS] = { 0, BASE_COIN };

//                               -     PONY
const int64_t CENT[N_COLORS] = { 0, BASE_CENT };

// related to max supply
//                            -      PONY
//                            -    210,000,000
const int DIGITS[N_COLORS] = {0,             9 };


// related to divisibility in GUI
// should be consistent with behavior due to COLOR_UNITS
//                              -         PONY
//                              -       0.0001
const int DECIMALS[N_COLORS] = {0,           4 };


// this test is here to help with consistency
// but it could be that there could be a mix of coinage dependent and not
#if COINAGE_DEPENDENT_POS
// colored coins are generated based on relative preponderance
// these are in order of PNY_COLOR
// if a currency can't mint, then this value is not relevant
//                                           -  PONY
const int64_t STAKE_MULTIPLIER[N_COLORS] = { 0,   1 };

#else
// If a currency can't mint, then this value is not relevant.
// These are somewhat like markers, and are
//    used for calculations in GetProofOfStakeReward().
// mint color (in order of PNY_COLOR)       -       PONY
const int64_t BASE_POS_REWARD[N_COLORS] = { 0,   BASE_COIN };

const int64_t HYPERINFLATION_LIMIT[N_COLORS] = {0, BASE_COIN * 2100000000};
#endif

// IMPORTANT: make sure these values are in smallest divisible units
//                                                       PONY
//                                    -           21,000,000,000
const int64_t MAX_MONEY[N_COLORS] = { 0, BASE_COIN * 21000000000 };
                   

// Fees are complicated. Each currency can be sent with a fee payable in it's
// FEE_COLOR. Most of the times the FEE_COLOR is the transaction currency itself.
// For example, the fee currency for PONY is PONY. However, delegating a fee currency
// is necessary for atomic currencies with a low coin count. They would cease to
// be useful very quickly.
const int FEE_COLOR[N_COLORS] = { (int) PNY_COLOR_NONE,
                                  (int) PNY_COLOR_PONY };


// MIN_TX_FEE, MIN_RELAY_TX_FEE, and OP_RET_FEE_PER_CHAR are in units of the **FEE_COLOR**

// $2 M cap -> ~$0.001 tx fee
// if cap grows to $20 B, then readjust
// min tx fees are *not* weighted by a priority multiplier
const int64_t MIN_TX_FEE[N_COLORS] = {0, BASE_CENT * 15 };


const int64_t MIN_RELAY_TX_FEE[N_COLORS] = {0, BASE_CENT * 15 };


// (0.015 per byte)
const int64_t COMMENT_FEE_PER_CHAR[N_COLORS] = { 0, BASE_CENT * 15 / 10 };


// op returns can be big, but they are expensive (0.015 per byte)
const int64_t OP_RET_FEE_PER_CHAR[N_COLORS] = { 0, BASE_CENT * 23 / 10 };


// Can the currency be recovered by fee scavenging?
//                                     -     PONY
const bool SCAVENGABLE[N_COLORS] = { false, true };


//                                          -     PONY
const int64_t MIN_TXOUT_AMOUNT[N_COLORS] = {0, BASE_CENT };


//                                          -     PONY
const int64_t MIN_INPUT_VALUE[N_COLORS] = {0,  BASE_CENT };


// combine threshold for creating coinstake
// if a currency can't stake, then this value is not relevant
// IMPORTANT: make sure these values are in smallest divisible units
//                                                  -         PONY
const int64_t STAKE_COMBINE_THRESHOLD[N_COLORS] = { 0, BASE_COIN * 1000 };


// what does a given currency mint (see GetProofOfStakeReward)
// these are in order of PNY_COLOR
const int MINT_COLOR[N_COLORS] = { (int) PNY_COLOR_NONE,
                                   (int) PNY_COLOR_PONY };

const char *COLOR_TICKER[N_COLORS] = { "<none>", "XPN" };
                   
const char *COLOR_NAME[N_COLORS] = { "<none>", "PonyCoin" };


// these must be unique, except color none (first) is 0 or 0, 0 etc.
// for thousands of currencies, initialize with a loop

// first dimension is indexed by ADDESS_VERSION_INDEX enum
// IMPORTANT: don't use aColorID directly, it gets copied to vector COLOR_ID
// Yes, fitting the deck into one byte is going to make for some ugly addresses.
const unsigned char aColorID[N_VERSIONS][N_COLORS][N_COLOR_BYTES] = {
                                                                  //      -    PONY
        /* Main Net PUBKEY */                                          { {0}, {177} },
        /* Main Net SCRIPT */                                          { {0}, { 32} },
        /* Test Net PUBKEY */                                          { {0}, {232} },
        /* Test Net SCRIPT */                                          { {0}, { 90} } };


// COLOR_ID (vector version of 3D aColorID)
std::vector<std::vector<std::vector<unsigned char> > > COLOR_ID(
                       N_VERSIONS, std::vector<std::vector<unsigned char> >(
                            N_COLORS, std::vector<unsigned char>(N_COLOR_BYTES)));

// Think of PRIORITY_MULTIPLIER this way:
//              priority ~ multiplier[color] * value_in * confs
// where value_in is in smallest divisible units (e.g. bitcoin -> satoshi).
// Miners will have to adjust these or have them set dynamically
// from the exchange values.

// PRIORITY_MULTIPLIER also adjusts fee-based prioritization.
// PRIORITY_MULTIPLIER should take into account these differences:
//   - total coin counts of the currencies
//   - differences in exchange values
//   - differences in how COIN is defined for each currency
// TODO: make this adjustable by RPC and configurable in the init.
//                                                 PONY
const int64_t PRIORITY_MULTIPLIER[N_COLORS] = { 0,   1 };


// their weights determine how readily they stake
// these are in order of PNY_COLOR
// IMPORTANT: make sure to take money supply into account right here, these are per coin
//                                        -        PONY
const int64_t WEIGHT_MULTIPLIER[N_COLORS] = { 0,     1 };


// These are for the premine blocks.
// IMPORTANT: make sure these values are in smallest divisible units
//      the smallest divisble unit of PONY is the integer 1, which is the same as an unitoshi
//                                     -             PONY
//                                               210,000,000
const int64_t POW_SUBSIDY[N_COLORS] = {0,   BASE_COIN * 210000000};


// MAPS_COLOR_ID is to look up values in case there are many currencies
// has this structure: 
//      [ {version1_bytes_color1 : color1, version1_bytes_color2, ...},
//        {version2_bytes_color1 : color1, version2_bytes_color2, ...}, ... ]
std::vector<std::map <std::vector <unsigned char>, int > > MAPS_COLOR_ID;


//////////////////////////////////////////////////////////////////////
///
/// GUI Constants
///
//////////////////////////////////////////////////////////////////////

// The default currency for the gui-less client is NONE.
// These are default currencies for the gui client, where the user
//    will need to have an operational client without any configuration.
const int DEFAULT_COLOR = (int) PNY_COLOR_PONY;
const int DEFAULT_STAKE_COLOR = (int) PNY_COLOR_PONY;

// For the gui, how divisible is the currency?
// For example, BTC is 3 (BTC, mBTC, uBTC)
// PONY gui is strangely simplified
//                                 -  PONY
const int COLOR_UNITS[N_COLORS] = {0,   2 };


// The GUI can create overview stats for only a few (e.g. 3) currencies.
// These are the default ordering
const int aGuiOverviewColors[N_GUI_OVERVIEW_COLORS] = { PNY_COLOR_PONY };

// A vector is used so that number of currencies may be dynamic.
std::vector<int> GUI_OVERVIEW_COLORS;


//////////////////////////////////////////////////////////////////////
///
/// Currency Methods
///
//////////////////////////////////////////////////////////////////////

int GetDayReward(int day)
{
   if (day >= POW_DAYS)
   {
      return 0;
   }
   return DAY_REWARDS[day];
}

bool GetColorFromTicker(const std::string &ticker, int &nColorIn)
{
    nColorIn = (int) PNY_COLOR_NONE;
    for (int nColor = 1; nColor < N_COLORS; ++nColor)
    {
           if (std::string(COLOR_TICKER[nColor]) == ticker)
           {
                 nColorIn = nColor;
                 return true;
           }
    }
    return false;
}

bool GetTickerFromColor(int nColor, std::string &ticker)
{
     if (nColor < 1 || nColor > N_COLORS)
     {
              ticker = COLOR_TICKER[PNY_COLOR_NONE];
              return false;
     }
     ticker = COLOR_TICKER[nColor];
     return true;
}

bool CheckColor(int nColor)
{
    return (nColor >= 1 && nColor < N_COLORS);
}

bool CanStake(int nColor)
{
    if (!CheckColor(nColor))
    {
        return false;
    }
    if (MINT_COLOR[nColor] == PNY_COLOR_NONE)
    {
        return false;
    }
    return true;
}



int GetStakeMinConfirmations(int nColor)
{
    if (!CanStake(nColor))
    {
       return std::numeric_limits<int>::max();
    }
    if (fTestNet)
    {
       return nStakeMinConfirmationsTestnet;
    }
    return nStakeMinConfirmations;
}


bool SplitQualifiedAddress(const std::string &qualAddress,
                              std::string &address, int &nColor, bool fDebug)
{

    // find the delimeter
    size_t x = qualAddress.find(ADDRESS_DELIMETER);
    if (x == std::string::npos)
    {
          if (fDebug)
          {
              printf("Unable to find ticker suffix for %s\n", qualAddress.c_str());
          }
          return false;
    }

    // make the ticker, check, set nColor
    std::string ticker = qualAddress.substr(x + ADDRESS_DELIMETER.size(),
                                                          qualAddress.size());
    if (!GetColorFromTicker(ticker, nColor))
    {
          if (fDebug)
          {
              printf("Ticker is not valid for %s\n", qualAddress.c_str());
          }
          return false;
    }

    // make the address
    address = qualAddress.substr(0, x);

    return true;
}

// add b58 compatible bytes of n to end of vch, little byte first
bool AppendColorBytes(int n, std::vector<unsigned char> &vch)
{
        if(!CheckColor(n))
        {
               return false;
        }
        while (n >= 256)
        {
            vch.push_back(n & 255);   //  fast % 256
            n = n >> 8;               //  fast / 256
        }
        vch.push_back(n);
        return true;
}



//////////////////////////////////////////////////////////////////////
///
/// Data Structures
///
//////////////////////////////////////////////////////////////////////

bool ValueMapAllPositive(const std::map<int, int64_t> &mapNet)
{
    if (mapNet.empty())
    {
       return false;
    }
    std::map<int, int64_t>::const_iterator itnet;
    for (itnet = mapNet.begin(); itnet != mapNet.end(); ++itnet)
    {
        if (itnet->second <= 0)
        {
            return false;
        }
    }
    return true;
}

bool ValueMapAllZero(const std::map<int, int64_t> &mapNet)
{
    std::map<int, int64_t>::const_iterator itnet;
    for (itnet = mapNet.begin(); itnet != mapNet.end(); ++itnet)
    {
        if (itnet->second != 0)
        {
            return false;
        }
    }
    return true;
}


// effectively mapCredit - mapDebit
void FillNets(const std::map<int, int64_t> &mapDebit,
              const std::map<int, int64_t> &mapCredit,
              std::map<int, int64_t> &mapNet)
{
    mapNet = mapCredit;
    std::map<int, int64_t>::iterator itnet;
    std::map<int, int64_t>::const_iterator itdeb;
    for (itnet = mapNet.begin(); itnet != mapNet.end(); ++itnet)
    {
        for (itdeb = mapDebit.begin(); itdeb != mapDebit.end(); ++itdeb)
        {
            if (itnet->first == itdeb->first)
            {
                itnet->second -= itdeb->second;
                break;
            }
        }
    }
    for (itdeb = mapDebit.begin(); itdeb != mapDebit.end(); ++itdeb)
    {
        itnet = mapNet.find(itdeb->first);
        if (itnet == mapNet.end())
        {
            mapNet[itdeb->first] = -itdeb->second;
        }
    }
}

// pony
bool PonyCheck(std::string sHash)
{
    const char chPony = '9';
    bool fOK = false;
    for (unsigned int i = 0; i < sHash.size(); ++i)
    {
        if (sHash[i] == '0')
        {
           continue;
        }
        if (sHash[i] == chPony)
        {
           fOK = true;
        }
        break;
    }
    return fOK;
}

