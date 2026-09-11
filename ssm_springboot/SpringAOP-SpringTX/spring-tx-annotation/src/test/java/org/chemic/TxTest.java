package org.chemic;

import org.chemic.config.JavaConfig;
import org.chemic.service.StudentService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.junit.jupiter.SpringJUnitConfig;

/**
 * projectName: com.atguigu.test
 *
 * description:
 */
@SpringJUnitConfig(JavaConfig.class)
public class TxTest {

    @Autowired
    private StudentService studentService;

    @Test
    public void  testTx(){
        studentService.changeInfo();
    }
}
