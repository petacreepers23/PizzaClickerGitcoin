const HDWalletProvider = require("@truffle/hdwallet-provider");

module.exports = {
//	emerald_local: {
//  url: "http://localhost:8545",
//  provider: function() {
//    return new HDWalletProvider(process.env.PRIVATE_KEYS.split(","), "http://localhost:8545");
//  },
//  network_id: "*"
//},
	emerald_testnet: {
	  url: "https://testnet.emerald.oasis.dev:8545",
	  provider: function() {
	    return new HDWalletProvider(process.env.PRIVATE_KEY, "https://testnet.emerald.oasis.dev");
	  },
	  network_id: "*"
	}
//emerald_mainnet: {
//  url: "https://emerald.oasis.dev:8545",
//  provider: function() {
//    return new HDWalletProvider(process.env.PRIVATE_KEY, "https://emerald.oasis.dev");
//  },
//  network_id: "*"
//}
  // Uncommenting the defaults below
  // provides for an easier quick-start with Ganache.
  // You can also follow this format for other networks.
  // See details at: https://trufflesuite.com/docs/truffle/reference/configuration
  // on how to specify configuration options!
  //
  //networks: {
  //  development: {
  //    host: "127.0.0.1",
  //    port: 7545,
  //    network_id: "*"
  //  },
  //  test: {
  //    host: "127.0.0.1",
  //    port: 7545,
  //    network_id: "*"
  //  }
  //},
  //
  // Truffle DB is currently disabled by default; to enable it, change enabled:
  // false to enabled: true. The default storage location can also be
  // overridden by specifying the adapter settings, as shown in the commented code below.
  //
  // NOTE: It is not possible to migrate your contracts to truffle DB and you should
  // make a backup of your artifacts to a safe location before enabling this feature.
  //
  // After you backed up your artifacts you can utilize db by running migrate as follows:
  // $ truffle migrate --reset --compile-all
  //
  // db: {
    // enabled: false,
    // host: "127.0.0.1",
    // adapter: {
    //   name: "sqlite",
    //   settings: {
    //     directory: ".db"
    //   }
    // }
  // }
};
