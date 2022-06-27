use std::env;
use std::str::FromStr;

use web3::types::{H160, U256};

fn wei_to_eth(wei: U256) -> f64 {
    let res = wei.as_u128() as f64;
    res / 1_000_000_000_000_000_000.0
}

#[tokio::main]
async fn main() -> web3::Result<()> {
    dotenv::dotenv().ok();

    let websocket = web3::transports::WebSocket::new(&env::var("INFURA_RINKEBY").unwrap()).await?;
    let web3s = web3::Web3::new(websocket);

    let mut accounts = web3s.eth().accounts().await?;
    accounts.push(H160::from_str(&env::var("ACCOUNT_ADDRESS").unwrap()).unwrap());
    println!("Accounts: {:?}", accounts);

    for account in accounts {
        let balance = web3s.eth().balance(account, None).await?;
        println!(
            "ROSE balance of {:?}: {}",
            account,
            wei_to_eth(balance)
        );
    }
    
    Ok(())
}
