#include "MdSpi.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <unistd.h>
#include <ThostFtdcMdApi.h>
#include "_cgo_export.h"
using namespace std;

#pragma warning(disable : 4996)

// USER_API参数
//extern CThostFtdcMdApi* pUserApi;

// 配置参数
extern char FRONT_ADDR[];
extern TThostFtdcBrokerIDType	BROKER_ID;
extern TThostFtdcInvestorIDType INVESTOR_ID;
extern TThostFtdcPasswordType	PASSWORD;
extern char* ppInstrumentID[];
extern int iInstrumentID;

void CMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo,
		int nRequestID, bool bIsLast)
{
	cerr << "--->>> "<< __FUNCTION__ << endl;
	IsErrorRspInfo(pRspInfo);
}

void CMdSpi::OnFrontDisconnected(int nReason)
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	cerr << "--->>> Reason = " << nReason << endl;
}

void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

void CMdSpi::OnFrontConnected()
{
	cerr << "--->>> " << __FUNCTION__ << endl;
    __go__on_connected__();
}

void CMdSpi::SetMdUserApi(CThostFtdcMdApi* pUserApi){
    this->pUserApi = pUserApi;
}

void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{


	cerr << "--->>> " << __FUNCTION__ <<"User ID" << pRspUserLogin->UserID << endl;
    __go_on_rsp_user_login__(pRspUserLogin,
                         		pRspInfo, nRequestID, bIsLast);
}



void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << __FUNCTION__ << ", InstrumentID: " << pSpecificInstrument->InstrumentID << endl;

}

void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << __FUNCTION__ << endl;
}
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{

	cerr << __FUNCTION__ << endl;
//	cerr << "--->>> 合约号=" << pDepthMarketData->InstrumentID << endl;
//	cerr << "--->>> 最新价=" << pDepthMarketData->LastPrice << endl;
//	cerr << "--->>> AskPrice5=" << pDepthMarketData->AskPrice5 << endl;
//	cerr << "--->>> ExchangeID:=" << pDepthMarketData->ExchangeID << endl;
	__go_on_rsp_sub_market_data__(pDepthMarketData);
}

bool CMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
		cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	return bResult;
}
void CMdSpi::initUserApiInfo(char *BrokerID,char* InvestorID,char *Password){
	strcpy(this->BrokerID, BrokerID);
	strcpy(this->InvestorID, InvestorID);
	strcpy(this->Password, Password);
}
void CMdSpi::setGoMdSpi(void* pGoMdSpi){
    this->GoMdSpi = pGoMdSpi;
};
