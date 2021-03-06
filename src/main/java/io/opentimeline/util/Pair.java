// SPDX-License-Identifier: Apache-2.0
// Copyright Contributors to the OpenTimelineIO Project.

package io.opentimeline.util;

/**
 * A generic class that holds a pair of values.
 *
 * @param <T> type for first value
 * @param <U> type for second value
 */
public class Pair<T, U> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Pair))
            return false;
        boolean firstEqual =
                (((Pair<T, U>) obj).getFirst() == null && ((Pair<T, U>) obj).getFirst() == null) ||
                        ((Pair<T, U>) obj).getFirst().equals(this.getFirst());
        boolean secondEqual =
                (((Pair<T, U>) obj).getSecond() == null && ((Pair<T, U>) obj).getSecond() == null) ||
                        ((Pair<T, U>) obj).getSecond().equals(this.getSecond());
        return firstEqual && secondEqual;
    }

    @Override
    public String toString() {
        return this.getClass().getCanonicalName() +
                "(" +
                "first=" + this.getFirst().toString() +
                ", second=" + this.getSecond().toString() +
                ")";
    }
}