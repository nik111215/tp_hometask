#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::Return;


TEST(WeatherTestCase, WrongCity) {
    cpr::Response response_1;
    response_1.status_code = 401;
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get("agu"))
    .Times(1)
    .WillOnce(Return(response_1));

    ASSERT_THROW(wm.GetResponseForCity("agu"), std::invalid_argument);
}

TEST(WeatherTestCase, GetResponseForCity) {
    std::string city_name = "Ivanovo";
    cpr::Response response_2;
    response_2.status_code = 200;
    response_2.text = "{\"code\" : \"Kot\"}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city_name))
    .Times(1)
    .WillOnce(Return(response_2));

    json result = wm.GetResponseForCity(city_name);
    ASSERT_EQ(result["code"], "Kot");
}

TEST(WeatherTestCase, GetTemperature) {
    std::string city_name = "Ivanovo";
    cpr::Response response_3;
    response_3.status_code = 200;
    response_3.text = "{\"list\" : [{\"main\" : {\"temp\" : 45.0}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city_name))
    .Times(1)
    .WillOnce(Return(response_3));

    float result = wm.GetTemperature(city_name);
    ASSERT_EQ(result, 45.0);
}

TEST(WeatherTestCase, FindDiffBetweenTwoCities) {
    std::string city1 = "Ivanovo";
    cpr::Response response_4;
    response_4.status_code = 200;
    response_4.text = "{\"list\" : [{\"main\" : {\"temp\" : 43.0}}]}";

    std::string city2 = "Tula";
    cpr::Response response_5;
    response_5.status_code = 200;
    response_5.text = "{\"list\" : [{\"main\" : {\"temp\" : 25.5}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city1))
    .Times(1)
    .WillOnce(Return(response_4));

    EXPECT_CALL(wm, Get(city2))
    .Times(1)
    .WillOnce(Return(response_5));

    float result = wm.FindDiffBetweenTwoCities(city1, city2);
    ASSERT_EQ(result, 17.5);
}

TEST(WeatherTestCase, GetDifferenceString) {
    std::string city1 = "Ivanovo";
    cpr::Response custom_response1;
    custom_response1.status_code = 200;
    custom_response1.text = "{\"list\" : [{\"main\" : {\"temp\" : 45.0}}]}";

    std::string city2 = "Tula";
    cpr::Response custom_response2;
    custom_response2.status_code = 200;
    custom_response2.text = "{\"list\" : [{\"main\" : {\"temp\" : 27.5}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city1))
    .Times(1)
    .WillOnce(Return(custom_response1));

    EXPECT_CALL(wm, Get(city2))
    .Times(1)
    .WillOnce(Return(custom_response2));

    std::string result = wm.GetDifferenceString(city1, city2);
    std::string verdict = "Weather in Ivanovo is warmer than in Tula by 17 degrees";
    ASSERT_EQ(result, verdict);
}

TEST(WeatherTestCase, GetDifferenceString2) {
    std::string city1 = "Ivanovo";
    cpr::Response response_6;
    response_6.status_code = 200;
    response_6.text = "{\"list\" : [{\"main\" : {\"temp\" : 37.0}}]}";

    std::string city2 = "Tula";
    cpr::Response response_7;
    response_7.status_code = 200;
    response_7.text = "{\"list\" : [{\"main\" : {\"temp\" : 12.5}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city1))
    .Times(1)
    .WillOnce(Return(response_6));

    EXPECT_CALL(wm, Get(city2))
    .Times(1)
    .WillOnce(Return(response_7));

    std::string result = wm.GetDifferenceString(city2, city1);
    std::string verdict = "Weather in Tula is colder than in Ivanovo by 24 degrees";
    ASSERT_EQ(result, verdict);
}


TEST(WeatherTestCase, SetApiKey) {
    WeatherMock wm;
    ASSERT_NO_THROW(wm.SetApiKey("some key"));
}

