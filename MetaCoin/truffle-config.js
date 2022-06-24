const HDWalletProvider = require("@truffle/hdwallet-provider");

module.exports = {
	emerald_testnet: {
	  url: "https://testnet.emerald.oasis.dev:8545",
	  provider: function() {
	    return new HDWalletProvider(process.env.PRIVATE_KEY, "https://testnet.emerald.oasis.dev");
	  },
	  network_id: "*"
	}//,
   //emerald_mainnet: {
   //  url: "https://emerald.oasis.dev:8545",
   //  provider: function() {
   //    return new HDWalletProvider(process.env.PRIVATE_KEY, "https://emerald.oasis.dev");
   //  },
   //  network_id: "*"
   //}

};
