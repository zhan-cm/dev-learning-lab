package top.zhan.service;

import com.alibaba.csp.sentinel.adapter.spring.webmvc.callback.BlockExceptionHandler;
import com.alibaba.csp.sentinel.slots.block.BlockException;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.stereotype.Component;

@Component // 交给 Spring 容器管理
public class CustomBlockExceptionHandler implements BlockExceptionHandler {

    @Override
    public void handle(HttpServletRequest request, HttpServletResponse response, BlockException e) throws Exception {
        // 设置返回状态码为 200，表示请求成功到达了后端，只是被拦截了
        response.setStatus(200);
        // 设置返回格式为 JSON 和中文字符集
        response.setContentType("application/json;charset=utf-8");
        
        // 模拟你们项目中标准的 JSON 返回格式
        String jsonResult = "{\"code\": 500, \"msg\": \"服务器太火爆啦，当前排队人数过多，请稍后再试！\"}";
        
        response.getWriter().write(jsonResult);
    }
}