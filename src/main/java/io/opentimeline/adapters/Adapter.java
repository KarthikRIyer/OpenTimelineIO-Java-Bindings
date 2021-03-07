package io.opentimeline.adapters;

import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(Adapters.class)
public @interface Adapter {
    String name();

    String classname();

    String[] suffixes();
}