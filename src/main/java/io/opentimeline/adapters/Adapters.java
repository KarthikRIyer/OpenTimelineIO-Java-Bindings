package io.opentimeline.adapters;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
@interface Adapters {
    Adapter[] value();
}