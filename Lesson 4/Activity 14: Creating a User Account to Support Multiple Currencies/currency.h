
// Each currency is caraterized by a conversion from a base currency.
// This number allows us to define a new currency by just providing
// the conversion value.
// We define an immaginary base currency, and we can get the value in any
// currency by computing:
// value (immaginary currency) * conversion rate = this currency value
template<int CurrencyConversion>
struct Currency {
    // Store the rate so we can use it when converting between currencies
    static const int conversionRate = CurrencyConversion;
    // Note: an int is not a good type to store monetary values.
    //       if you need to store money values use an appropriate library.
    int d_value;

    Currency(int value): d_value(value) {}

};

// Convert a currency to another.
// We bring the first currency value to the base immaginary currency value,
// then we convert back to the new currency
template<typename OtherCurrency, typename SourceCurrency>
OtherCurrency to(const SourceCurrency& source) {
    // Note: we need to convert to float here, otherwise this is a division
    // between integers and it will be rounded to an int.
    float baseValue = source.d_value / float(source.conversionRate);
    // Here we explicitly convert back to an int. This will truncate the decimals
    int otherCurrencyValue = int(baseValue * OtherCurrency::conversionRate);
    return OtherCurrency(otherCurrencyValue);
}

// We defined 3 currency, based on their conversion rate.
// After this we can use USD, EUR and GBP as if we typed Currency<the conversion rate>
using USD = Currency<100>;
using EUR = Currency<87>;
using GBP = Currency<78>;
