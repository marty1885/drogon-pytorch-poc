#include <drogon/HttpController.h>
#include <torch/torch.h>
#include <ATen/ATen.h>

using namespace drogon;

class testctl : public drogon::HttpController<testctl>
{
public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    ADD_METHOD_TO(testctl::invoke,"/models/{1:model_name}/invoke", Get);
    METHOD_LIST_END
    void invoke(const HttpRequestPtr &, std::function<void (const HttpResponsePtr &)> &&callback, std::string model_name) const
    {
        LOG_DEBUG <<"invoke model: " << model_name;
        //Authentication algorithm, read database, verify identity, etc...
        //...
        at::Tensor a = at::ones({2, 2}, at::kInt);
        at::Tensor b = at::randn({2, 2});
        auto c = a + b.to(at::kInt);
        Json::Value ret;
        ret["hello"] = "world";
        ret["uuid"] = drogon::utils::getUuid();
        auto resp=HttpResponse::newHttpJsonResponse(ret);
        callback(resp);        
    }
};
