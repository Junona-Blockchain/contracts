#include <eosio.system/eosio.system.hpp>
#include <eosio.token/eosio.token.hpp>
#include <eosio.vote/eosio.vote.hpp>

#include <eosio/transaction.hpp>
#include <math.h>

namespace eosiosystem {

   using eosio::current_time_point;
   using eosio::token;
   using eosio::vote;
   using eosio::symbol;
   using eosio::symbol_code;
   using eosio::microseconds;

   void system_contract::startauction() {
      auto producers_size = std::distance(_producers.cbegin(), _producers.cend());
      const asset token_supply = token::get_supply(token_account, core_symbol().code());
      const asset vote_supply = vote::get_supply(vote_account, symbol_code("VOTE"));
      const int64_t amount = token_supply.amount;
      const int amount_producers = (int) log(amount);
      const int64_t vote_amount = vote_supply.amount;

      if (vote_amount < producers_size) {
         _gstate4.vote_auction_started = true;
      }
   }

   void system_contract::auctstatus() {
      eosio::print(_gstate4.vote_auction_started);
   }
}

