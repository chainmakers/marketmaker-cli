#include <gmock/gmock.h>

#include <api_help.h>

#include "property_utils.h"

TEST(ApiHelpTests, parseCurrentHelp) {
    // Output generated by:
    // $ curl -qs --url http://127.0.0.1:7783 --data '{"method":"help"}'
    const char *currentHelp = "{\"result\":\" available localhost RPC commands: \n"
            " setprice(base, rel, price, broadcast=1)\n"
            "autoprice(base, rel, fixed, minprice, maxprice, margin, refbase, refrel, factor, offset)*\n"
            "goal(coin=*, val=<autocalc>)\n"
            "myprice(base, rel)\n"
            "enable(coin)\n"
            "disable(coin)\n"
            "notarizations(coin)\n"
            "statsdisp(starttime=0, endtime=0, gui=, pubkey=, base=, rel=)\n"
            "ticker(base=, rel=)\n"
            "tradesarray(base, rel, starttime=<now>-timescale*1024, endtime=<now>, timescale=60) -> [timestamp, high, low, open, close, relvolume, basevolume, aveprice, numtrades]\n"
            "pricearray(base, rel, starttime=0, endtime=0, timescale=60) -> [timestamp, avebid, aveask, highbid, lowask]\n"
            "getrawtransaction(coin, txid)\n"
            "inventory(coin, reset=0, [passphrase=])\n"
            "lastnonce()\n"
            "buy(base, rel, price, relvolume, timeout=10, duration=3600, nonce)\n"
            "sell(base, rel, price, basevolume, timeout=10, duration=3600, nonce)\n"
            "withdraw(coin, outputs[])\n"
            "sendrawtransaction(coin, signedtx)\n"
            "swapstatus(pending=0)\n"
            "swapstatus(coin, limit=10)\n"
            "swapstatus(base, rel, limit=10)\n"
            "swapstatus(requestid, quoteid, pending=0)\n"
            "recentswaps(limit=3)\n"
            "notarizations(coin)\n"
            "public API:\n"
            " getcoins()\n"
            "getcoin(coin)\n"
            "portfolio()\n"
            "getpeers()\n"
            "passphrase(passphrase, gui, netid=0, seednode=)\n"
            "listunspent(coin, address)\n"
            "setconfirms(coin, numconfirms, maxconfirms=6)\n"
            "trust(pubkey, trust) # positive to trust, 0 for normal, negative to blacklist\n"
            "balance(coin, address)\n"
            "balances(address)\n"
            "fundvalue(address=, holdings=[], divisor=0)\n"
            "orderbook(base, rel, duration=3600)\n"
            "getprices()\n"
            "getmyprice(base, rel)\n"
            "getprice(base, rel)\n"
            "//sendmessage(base=coin, rel=, pubkey=zero, <argjson method2>)\n"
            "//getmessages(firsti=0, num=100)\n"
            "//deletemessages(firsti=0, num=100)\n"
            "secretaddresses(prefix='secretaddress', passphrase, num=10, pubtype=60, taddr=0)\n"
            "electrum(coin, ipaddr, port)\n"
            "snapshot(coin, height)\n"
            "snapshot_balance(coin, height, addresses[])\n"
            "dividends(coin, height, <args>)\n"
            "stop()\n"
            "bot_list()\n"
            "bot_statuslist()\n"
            "bot_buy(base, rel, maxprice, relvolume) -> botid\n"
            "bot_sell(base, rel, minprice, basevolume) -> botid\n"
            "bot_settings(botid, newprice, newvolume)\n"
            "bot_status(botid)\n"
            "bot_stop(botid)\n"
            "bot_pause(botid)\n"
            "calcaddress(passphrase)\n"
            "instantdex_deposit(weeks, amount, broadcast=1)\n"
            "instantdex_claim()\n"
            "jpg(srcfile, destfile, power2=7, password, data=, required, ind=0)\n"
            "\"}";
    Property props[] = {
            { "setprice", "base,rel,price,broadcast" },
            { "autoprice", "base,rel,fixed,minprice,maxprice,margin,refbase,refrel,factor,offset" },
            { "goal", "coin,val" },
            { "myprice", "base,rel" },
            { "enable", "coin" },
            { "disable", "coin" },
            { "notarizations", "coin" },
            { "statsdisp", "starttime,endtime,gui,pubkey,base,rel" },
            { "ticker", "base,rel" },
            { "tradesarray", "base,rel,starttime,endtime,timescale" },
            { "pricearray", "base,rel,starttime,endtime,timescale" },
            { "getrawtransaction", "coin,txid" },
            { "inventory", "coin,reset,passphrase" },
            { "lastnonce", "" },
            { "buy", "base,rel,price,relvolume,timeout,duration,nonce" },
            { "sell", "base,rel,price,basevolume,timeout,duration,nonce" },
            { "withdraw", "coin,outputs" },
            { "sendrawtransaction", "coin,signedtx" },
            { "swapstatus", "pending" },
            { "swapstatus", "coin,limit" },
            { "swapstatus", "base,rel,limit" },
            { "swapstatus", "requestid,quoteid,pending" },
            { "recentswaps", "limit" },
            { "notarizations", "coin" },
            { "getcoins", "" },
            { "getcoin", "coin" },
            { "portfolio", "" },
            { "getpeers", "" },
            { "passphrase", "passphrase,gui,netid,seednode" },
            { "listunspent", "coin,address" },
            { "setconfirms", "coin,numconfirms,maxconfirms" },
            { "trust", "pubkey,trust" },
            { "balance", "coin,address" },
            { "balances", "address" },
            { "fundvalue", "address,holdings,divisor" },
            { "orderbook", "base,rel,duration" },
            { "getprices", "" },
            { "getmyprice", "base,rel" },
            { "getprice", "base,rel" },
            { "secretaddresses", "prefix,passphrase,num,pubtype,taddr" },
            { "electrum", "coin,ipaddr,port" },
            { "snapshot", "coin,height" },
            { "snapshot_balance", "coin,height,addresses" },
            { "dividends", "coin,height" },
            { "stop", "" },
            { "bot_list", "" },
            { "bot_statuslist", "" },
            { "bot_buy", "base,rel,maxprice,relvolume" },
            { "bot_sell", "base,rel,minprice,basevolume" },
            { "bot_settings", "botid,newprice,newvolume" },
            { "bot_status", "botid" },
            { "bot_stop", "botid" },
            { "bot_pause", "botid" },
            { "calcaddress", "passphrase" },
            { "instantdex_deposit", "weeks,amount,broadcast" },
            { "instantdex_claim", "" },
            { "jpg", "srcfile,destfile,power2,password,data,required,ind" },
    };
    err_t err;
    PropertyGroup expectedApi = {
            DIMOF(props), props
    };
    PropertyGroup *api = parse_api_help(currentHelp, &err);
    ASSERT_EQ(0, err);
    ASSERT_EQ(expectedApi, *api);
}
